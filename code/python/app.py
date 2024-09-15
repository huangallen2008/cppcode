from flask import Flask, request, session, redirect,render_template
app = Flask(__name__)
@app.route('/login')
def login():
    return render_template('login.html')

@app.route('/logout')
def logout():
    session.pop('login_user', None)
    return redirect('/login')

@app.route('/login', methods=['POST'])
def login_post():
    username = request.form.get('username')
    return username + '登入成功'

@app.route('/transfer', methods=['GET', 'POST'])
def transfer():
    username = session.get('login_user')
    if username is None:
        print('用戶未登入!')
        return '登入後操作!'
    
    to_user = request.form.get('to_user')
    money = int(request.form.get('money'))
    msg = f'{username}給[{to_user}] 轉帳{money}元成功'
    print(msg)
    return msg

if __name__ == '__main__':
    app.run()
