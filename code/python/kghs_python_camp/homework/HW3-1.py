from urllib.request import urlopen,Request
from bs4 import BeautifulSoup
url = 'https://web.ee.ntu.edu.tw/teacher_index_all.php'
html = urlopen(url).read().decode()
bsObj = BeautifulSoup(html,"html.parser")
teacher_list = bsObj.find("div",{"id":"display_type2"}).findAll("tr")
teacher_list=teacher_list[1:]
for atc in teacher_list:
    name=atc.find("a").get_text()
    job_kind=atc.findAll("td")
    job=job_kind[1].get_text()
    kind=job_kind[2].get_text()
    email=str(atc.find("img")).split(" ")[1][5:-1]
    print(name+" "+email+" "+job+" "+kind)
    


