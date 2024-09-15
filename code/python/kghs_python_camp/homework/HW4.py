from flask import Flask
from flask_mail import Mail
from flask_mail import Message
app = Flask(__name__)
@app.route('/')
def index():
    html = '''<form action='/email'><table border>\n'''
    html+='<tr><td>學號</td><td>姓名</td><td>成績</td></tr>'
    infile = open('score.txt', "r")
    aList = infile.readlines()
    for line in aList:
        list=line.split(" ")
        html+='<tr>'
        html+='<td>{}</td><td>{}</td>'.format(list[0],list[1])
        if int(list[2])<60:
            html+='<td><font color="red">{}</font></td>'.format(list[2])
        else:
            html+='<td>{}</td>'.format(list[2])
        html+='</tr>'
    infile.close()
    html += '</table>\n<input type=submit value="Email students">'
    return html
@app.route('/email')
def email():
    html='Mail sent to students:<ol>\n'
    infile=open('score.txt',"r")
    aList=infile.readlines()
    for line in aList:
        mail=Mail(app)
        list=line.split(" ")
        html+='<li>{} {}\n'.format(list[0],list[1])
        msg=Message('Midtern Exam',sender='s7082@kghs.ncnu.net',\
        recipients=['huangallen001@gmail.com'])
        msg.body='''Hi {},\nYour midterm exam grade is {}.'''.format(list[1],list[2])
        msg.html='''<h1>期中考成績通知</h1><br>親愛的 {} 同學你好:<br>謹在此通知你, 本次期中考成績為 {}.<br>如對成績有任何意見, 請上 <a href="https://www.kshs.kh.edu.tw">校務建言系統</a> 填寫. 謝謝.'''.format(list[1],list[2])
        with app.app_context():
            mail.send(msg)
    html+='</ol>\n'
    return html
