import sqlite3
db_filename = 'test.db'
conn = sqlite3.connect(db_filename)
cursor = conn.cursor()
infile=open('ts300.txt','r')
ts300=infile.read().split('\n\n\n\n')
ts300.pop()
for item in ts300:
    lines=item.split("\n")
    while(lines[0]==""):
        item=item.lstrip()
        lines=lines[1:]
    apoem=item.split("\n\n")
    p_id=int(apoem[0].split("\n")[0])
    p_ti=str(apoem[0].split("\n")[1])
    p_pt=str(apoem[0].split("\n")[2])[3:]
    p_pm=str(apoem[1])
    print(p_id,p_ti,p_pt)
    stmt = "insert into ts300 values({},'{}','{}','{}')".format(p_id,p_ti,p_pt,p_pm)
    cursor.execute(stmt)
    conn.commit()

