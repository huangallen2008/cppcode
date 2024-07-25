from flask import Flask,request
app = Flask(__name__)

@app.route('/order')
def order():
    infile=open('lunch.txt',"r")
    html='''
    <form action='/accept'>
    <input type=text name=name>
    <select name="lunch">
    '''
    for line in infile:
        ch=line[:-1].split(':')
        html+='<option value={}(${})>{}(${})</option>'.format(ch[1],ch[2],ch[1],ch[2])
    html+= '''
    </select>
    <input type=submit>
    '''
    
    infile.close()
    return html

@app.route('/accept')
def accept():
    from datetime import datetime
    time=datetime.now().replace(microsecond=0)
    file=open('order.txt',"a")
    name=request.values['name']
    print("{} {} {}".format(time,name,request.values['lunch']),file=file)
    file.close()
    return "{} orders {}".format(name,request.values['lunch'])

@app.route('/total')
def total():
    html='''
    <table border>
    <tr><td><center><b>Time</b></center></td><td><center><b>Name</b></center></td><td><center><b>Meal</b></center></td></tr>
    '''
    sum_m=0
    infile=open('order.txt',"r")
    for line in infile :
        arr=line.split(' ')
        html+="<tr><td>{}</td><td>{}</td><td>{}</td></tr>".format(arr[0]+' '+arr[1],arr[2],arr[3])
        sum_m+=int(arr[3].split('(')[1][1:-2])
    
    html+="<tr><td></td><td>Total</td><td>${}</td></tr></table>".format(sum_m)
    infile.close()
    return html
    

