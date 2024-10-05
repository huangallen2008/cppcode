from flask import Flask, request, render_template, redirect, url_for
import json,sqlite3
app = Flask(__name__)

cart = [0 for i in range(0,1000)]
#infile=open("menu.txt",'r', encoding='utf-8')
#file=infile.readlines()
#mealsz=len(file)
#menu=[[0,'item','price']]

@app.route('/student',methods=['GET','post'])
def student():
    return render_template('student.html')

@app.route('/student/search',methods=['GET','post'])
def student_search():
    infile=open("menu.txt",'r', encoding='utf-8')
    menu=infile.readlines()
    menusz=len(menu)
    db_filename = 'order.db'
    conn = sqlite3.connect(db_filename)
    cursor = conn.cursor()
    stmt = "select * from orders WHERE 1=1 "
    grade='0'
    classid='0'
    number='0'
    date=''
    if 'grade' in request.values: grade=request.values['grade']
    if 'class' in request.values: classid=request.values['class']
    if 'number' in request.values: number=request.values['number']
    if 'date' in request.values: date=request.values['date']
    if grade!='0':  stmt+=" and grade='{}' ".format(grade)
    if classid!='0':  stmt+=" and class='{}' ".format(classid)
    if number!='0': stmt+=" and number='{}' ".format(number)
    if date!='':  stmt+=" and data='{}' ".format(date)

    cursor.execute(stmt)
    order_list=cursor.fetchall()
    print(stmt)
    html=render_template('student_search.html',order=order_list,mlsz=menusz,menu=menu)
    cursor.close()
    conn.close()
    return html

@app.route('/student/order', methods=['GET','post'])
def student_order():
    infile=open("menu.txt",'r', encoding='utf-8')
    menu=infile.readlines()
    menusz=len(menu)
    grade='0'
    classid='0'
    number='0'
    date=''
    if 'grade' in request.values: grade=request.values['grade']
    if 'class' in request.values: classid=request.values['class']
    if 'number' in request.values: number=request.values['number']
    if 'date' in request.values: date=request.values['date']
    return render_template('student_order.html', menu=menu,cart=cart,mlsz=menusz,grade=grade,classid=classid,number=number,date=date)

@app.route('/student/add_cart', methods=['post'])
def add_cart():
    infile=open("menu.txt",'r', encoding='utf-8')
    menu=infile.readlines()
    menusz=len(menu)
    mealid=int(request.values['meal'])
    infile=open("menu.txt",'r', encoding='utf-8')
    menu=infile.readlines()
    menusz=len(menu)
    if mealid==0: return render_template('student_order.html', menu=menu,cart=cart,mlsz=menusz)
    grade=request.values['grade']
    classid=request.values['class']
    number=request.values['number']
    date=request.values['date']
    print(grade,classid,number,date)
    
    if(date==''): return render_template('student_order.html', menu=menu,cart=cart,mlsz=menusz)
    quantity=int(request.values['quantity'])
    cart[mealid]+=quantity
    cart[mealid]=max(cart[mealid],0)
    return render_template('student_order.html', menu=menu,cart=cart,mlsz=menusz,grade=grade,classid=classid,number=number,date=date)

@app.route('/student/confirm', methods=['post'])
def confirm():
    infile=open("menu.txt",'r', encoding='utf-8')
    menu=infile.readlines()
    menusz=len(menu)
    grade=request.values['grade']
    classid=request.values['class']
    number=request.values['number']
    date=request.values['date']
    print(grade,classid,number,date)
    return render_template('confirm.html', menu=menu,cart=cart,mlsz=menusz,grade=grade,classid=classid,number=number,date=date)

@app.route('/student/accept',methods=['post'])
def accept():
    infile=open("menu.txt",'r', encoding='utf-8')
    menu=infile.readlines()
    menusz=len(menu)
    db_filename = 'order.db'
    conn = sqlite3.connect(db_filename)
    cursor = conn.cursor()
    cursor.execute("select * from orders")
    order_list=cursor.fetchall()
    indexn=int(order_list[int(len(order_list))-1][0])+1
    grade=request.values['grade']
    classid=request.values['class']
    number=request.values['number']
    date=request.values['date']
    print(grade,classid,number,date)
    for i in range(1,menusz):
        if cart[i]>0: 
            stmt = "INSERT INTO orders (indexn, grade, 'class', number, date, meal, qua,is_payed) values ('{}','{}', '{}', '{}', '{}', '{}', '{}','{}')".format(indexn,grade, classid, number, date, i, cart[i],0)
            cursor.execute(stmt)
    conn.commit()
    cursor.close()
    conn.close()

    html=render_template('accept.html', menu=menu,cart=cart,mlsz=menusz)
    for i in range(1,menusz): cart[i]=0
    return html

@app.route('/admin/order_search',methods=['GET','post'])
def order_search():
    infile=open("menu.txt",'r', encoding='utf-8')
    menu=infile.readlines()
    menusz=len(menu)
    db_filename = 'order.db'
    conn = sqlite3.connect(db_filename)
    cursor = conn.cursor()
    stmt = "select * from orders WHERE 1=1 "
    grade='0'
    classid='0'
    number='0'
    date=''
    is_payed='0'
    if 'grade' in request.values: grade=request.values['grade']
    if 'class' in request.values: classid=request.values['class']
    if 'number' in request.values: number=request.values['number']
    if 'date' in request.values: date=request.values['date']
    if 'is_payed' in request.values: is_payed=request.values['is_payed']
    if grade!='0':  stmt+=" and grade={} ".format(grade)
    if classid!='0':  stmt+=" and class={} ".format(classid)
    if number!='0': stmt+=" and number={} ".format(number)
    if date!='':  stmt+=" and data='{}' ".format(date)
    if is_payed!='0':  stmt+=" and is_payed={} ".format(is_payed)
    cursor.execute("select * from orders")
    order_list=cursor.fetchall()
    ordersz=len(order_list)
    for i in range(ordersz):
        if 'check{}'.format(i) in request.values: 
            print(i,request.values['check{}'.format(i)])
            if request.values['check{}'.format(i)]: cursor.execute("update orders set is_payed='1' where indexn={}".format(i))
            else: cursor.execute("update orders set is_payed=0 where indexn={}".format(i))
   
    cursor.execute(stmt)
    order_list=cursor.fetchall()
    #print(order_list)

    html=render_template('order_search.html',order=order_list,mlsz=menusz,menu=menu)
    html+='''
    <form method="post" action="/admin/order_search">
    <br><br>
    <table border>
        <tr><td>編號</td><td>年級</td><td>班級</td><td>座號</td><td>日期</td><td>餐點</td><td>數量</td><td>價格</td><td>付款狀態</td></tr>
    '''
    for line in order_list:
        indexn,grade,classs,number,date,meal,qua,is_payed = line 
        html+='''
        <tr>
        <td>{}</td>
        <td>{}</td>
        <td>{}</td>
        <td>{}</td>
        <td>{}</td>
        <td>{}</td>
        <td>{}</td>
        <td>
        '''.format(indexn,grade,classs,number,date,meal,qua)
        for i in range(1,menusz):
            alist=menu[i].split(' ')
            if int(alist[0])==int(meal):
                html+='{}'.format(int(qua)*int(alist[2]))
                break
        html+='''
        </td>
        <td><input type="checkbox" name="check{}" value="1"  
        '''.format(indexn)
        if int(is_payed)==1: html+=" checked "
        html+="></td></tr>"
    html+='''
    </table>
    </form>
    <form method="post" action="/admin">
        <button type="submit">back to /admin</button>
    </form>
    '''

    cursor.close()
    conn.close()
    return html

@app.route('/admin',methods=['GET','post'])
def admin():
    return render_template('admin.html')

@app.route('/admin/edit_menu',methods=['GET','post'])
def edit_menu():
    infile=open("menu.txt",'r', encoding='utf-8')
    menu=infile.readlines()
    menusz=len(menu)
    return render_template('edit_menu.html', menu=menu,mlsz=menusz)

    
@app.route('/admin/add_menu',methods=['GET','post'])
def add_menu():
    infile=open("menu.txt",'r', encoding='utf-8')
    menu=infile.readlines()
    menusz=len(menu)
    return render_template('add_menu.html', menu=menu,mlsz=menusz)

@app.route('/admin/append',methods=['GET','post'])
def append():
    infile=open("menu.txt",'r', encoding='utf-8')
    menu=infile.readlines()
    menusz=len(menu)
    file=open("menu.txt","a")
    print('{} {} {}'.format(str(menusz).zfill(5),request.values['item'],request.values['price']),file=file)
    return redirect(url_for('edit_menu'))

@app.route('/admin/remove_menu',methods=['GET','post'])
def remove_menu():
    infile=open("menu.txt",'r', encoding='utf-8')
    menu=infile.readlines()
    menusz=len(menu)
    return render_template('remove_menu.html', menu=menu,mlsz=menusz)

@app.route('/admin/remove',methods=['GET','post'])
def remove():
    infile=open("menu.txt",'r', encoding='utf-8')
    menu=infile.readlines()
    menusz=len(menu)
    for i in range(menusz):
        if int(menu[i][:-1].split(' ')[0])==int(request.values['item']) :
            menu.remove(menu[i])
            break
    
    file=open("menu.txt","w", encoding='utf-8')
    menusz-=1
    for i in range(menusz):
        print(menu[i],file=file,end='')
    return redirect(url_for('edit_menu'))

@app.route('/admin/change_menu',methods=['GET','post'])
def change_menu():
    infile=open("menu.txt",'r', encoding='utf-8')
    menu=infile.readlines()
    menusz=len(menu)
    return render_template('change_menu.html', menu=menu,mlsz=menusz)
    
@app.route('/admin/change',methods=['GET','post'])
def change():
    infile=open("menu.txt",'r', encoding='utf-8')
    menu=infile.readlines()
    menusz=len(menu)
    file=open("menu.txt","w", encoding='utf-8')
    for i in range(menusz):
        alist=menu[i][:-1].split(' ')
        if(int(alist[0])==int(request.values['number'])):
            if request.values['item']!='':alist[1]=request.values['item']
            alist[2]=request.values['price']
        for j in range(3): 
            print(alist[j],file=file,end=" ")
        print("",file=file)
    return redirect(url_for('edit_menu'))