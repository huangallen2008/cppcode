from flask import Flask,request
app = Flask(__name__)

@app.route('/sampling', methods=['GET', 'POST'])
def sample():
    if request.method == "GET":
        html = '''<form method="POST">
        <textarea name="students" rows=4 cols=50></textarea><br>
        Number of Samples: <select name="number">'''
        for i in range(1,8):
            html+="<option value='{}'>{}</option>".format(i,i)
        html+='''</select> <input type=submit> <input type=reset>'''
        return html
    else: # POST
        import random
        students = request.values['students'].split("\r\n")
        angry_students=random.sample(students,int(request.values['number']))
        html = '<ol>\n'
        for line in angry_students:
            html += '<li>' + line + '\n'
        html += '</ol>\n'
        return html
