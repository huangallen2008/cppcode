# # import matplotlib.pyplot as plt
# import csv

# from matplotlib import pyplot as plt

# # 開啟 CSV 檔案
# with open('F_I_star_data.csv', newline='') as csvfile:
#     # 讀取 CSV 檔案內容
#     data = csv.reader(csvfile)
#     # 提取 X 和 Y 座標
#     x = []
#     y = []
#     for row in data:
#         x.append(float(row[0]))  # 第一列為 X 座標
#         y.append(float(row[1]))  # 第二列為 Y 座標

# # 繪製數據點
# plt.scatter(x, y)
# plt.xlabel('X 軸標籤')
# plt.ylabel('Y 軸標籤')
# plt.title('數據點分佈')
# plt.grid(True)  # 添加網格線

# from matplotlib.widgets import Button, Slider

# # 創建一個子圖
# fig, ax = plt.subplots()
# line, = ax.plot(x, y)
# ax.set_xlim(0, 10)
# ax.set_ylim(-1, 1)
# # 定義放大和縮小函數
# def zoom(event):
#     if event.button == 'up':
#         ax.set_xlim(ax.get_xlim()[0] * 1.1, ax.get_xlim()[1] * 1.1)
#         ax.set_ylim(ax.get_ylim()[0] * 1.1, ax.get_ylim()[1] * 1.1)
#     elif event.button == 'down':
#         ax.set_xlim(ax.get_xlim()[0] * 0.9, ax.get_xlim()[1] * 0.9)
#         ax.set_ylim(ax.get_ylim()[0] * 0.9, ax.get_ylim()[1] * 0.9)
#     plt.draw()

# # 連接滑鼠滾輪事件
# fig.canvas.mpl_connect('scroll_event', zoom)

# plt.show()


import math
import matplotlib.pyplot as plt
from matplotlib.widgets import Button, Slider
import numpy as np
import csv
cnt=0
# 開啟 CSV 檔案
x=[]
y=[]
for i in range(1,100000):
    x.append(i)
    if(i==5): 
        print(math.log(i,2))
        print(i/math.log(i,2))
    if(i>1): y.append(i*100/math.log(i,2))
    else : y.append(1)
# with open('graph1.csv', newline='') as csvfile:
#     # 讀取 CSV 檔案內容
#     data = csv.reader(csvfile)
#     # 提取 X 和 Y 座標
#     x = []
#     y = []
#     for row in data:
#         cnt+=1
#         # if cnt>1000 : break
#         x.append(float(row[0]))  # 第一列為 X 座標
#         y.append(float(row[1]))  # 第二列為 Y 座標
cnt=0
with open('F_I_star_data.csv', newline='') as csvfile:
    # 讀取 CSV 檔案內容
    data = csv.reader(csvfile)
    # 提取 X 和 Y 座標
    x2 = []
    y2 = []
    for row in data:
        cnt+=1
        # if(cnt>1000):break
        x2.append(float(row[0]))  # 第一列為 X 座標
        y2.append(float(row[1]))  # 第二列為 Y 座標

    # 提取 X 和 Y 座標
    x3 = []
    y3 = []
    for i in range(1,1000):
        x3.append(i)  # 第一列為 X 座標
        y3.append(i-1)  # 第二列為 Y 座標
# 生成一些隨機數據
# x = np.linspace(0, 10, 100)
# y = np.sin(x)
# 創建一個子圖
fig, ax = plt.subplots()
ax.plot(x, y,color='red',markersize=1)
ax.plot(x2, y2,color='blue',markersize=1)
ax.plot(x3, y3,color='red',markersize=1)


# ax.set_xlim(min(x), max(x))
# ax.set_ylim(min(y), max(y))

# 定義放大和縮小函數
def zoom(event):
    axtemp=event.inaxes
    x_min, x_max = axtemp.get_xlim()
    xrang = (x_max - x_min) / 10
    y_min, y_max = axtemp.get_ylim()
    yrang = (y_max - y_min) / 10
    if event.button == 'up':
        ax.set_xlim(ax.get_xlim()[0] +xrang, ax.get_xlim()[1] -xrang)
        ax.set_ylim(ax.get_ylim()[0] +yrang, ax.get_ylim()[1] -yrang)
    elif event.button == 'down':
        ax.set_xlim(ax.get_xlim()[0] -xrang, ax.get_xlim()[1] +xrang)
        ax.set_ylim(ax.get_ylim()[0] -yrang, ax.get_ylim()[1] +yrang)
    plt.draw()

# if event.button == 'up':
#     axtemp. set(xlim=(x_min + fanwei, x_max - fanwei))
#     print('up')
# elif event.button == 'down':
#     axtemp.set(xlim=(x_min - fanwei, x_max + fanwei))
#     print('down')
# fig.canvas.draw_idle()# 绘图动作实时反映在图像上


# 連接滑鼠滾輪事件
fig.canvas.mpl_connect('scroll_event', zoom)
# plt.scatter(x, y,marker=".")
plt.xlabel('X')
plt.ylabel('Y')
plt.title('data')
plt.grid(True)  # 添加網格線
plt.show()
