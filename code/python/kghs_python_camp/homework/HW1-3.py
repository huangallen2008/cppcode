from flask import Flask,request
app = Flask(__name__)


@app.route('/')
def index():
    html = '''<form action=/whatday>
              <input type=date name=birthday>
              <input type=submit>
              </form>'''
    return html

@app.route('/whatday')
def whatday():
    from datetime import datetime
    weekdays = ["一", "二", "三", "四", "五", "六", "日"]
    birth_str=request.values['birthday']
    bd=datetime.strptime(birth_str,"%Y-%m-%d")
    html = '{} is 星期{}'.format(birth_str,weekdays[bd.isoweekday()-1])
    return html
