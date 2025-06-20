import jieba
import jieba.analyse
from bs4 import BeautifulSoup
from collections import Counter
import sys
 
jieba.setLogLevel(jieba.logging.INFO)
 
query_word = input().strip()
 
with open("index.html", "r", encoding="utf-8") as file:
    html_content = file.read()

 
soup = BeautifulSoup(html_content, "html.parser")
 
cards = soup.find_all(class_="card")  
texts = [card.get_text(strip=True) for card in cards]
full_text = ' '.join(texts)
 
tokens = list(jieba.cut(full_text))
 
stop_words = set([
    '所以', '好', '因為', '大家', '的', '是', '了', '我', '也', '在', '和', '就', '不', '有', '他', '她',
    '你', '我們', '這個', 'https', 'colab', 'com', 'research', 'google', 'drive', 'usp', 'sharing', 'scrollTo'
])
 
filtered_tokens = [word for word in tokens if word not in stop_words and len(word) > 1]
 
word_counts = Counter(filtered_tokens)
 
print(word_counts.get(query_word, 0))
 
tags = jieba.analyse.extract_tags(full_text, topK=15, withWeight=True)
print(tags)