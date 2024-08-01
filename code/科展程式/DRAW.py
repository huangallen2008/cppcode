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


import matplotlib.pyplot as plt
from matplotlib.widgets import Button, Slider
import numpy as np
import csv
cnt=0
maxd=600
# 開啟 CSV 檔案
with open('graph1.csv', newline='') as csvfile:
    # 讀取 CSV 檔案內容
    data = csv.reader(csvfile)
    # 提取 X 和 Y 座標
    x = []
    y = []
    cnt=0
    for row in data:
        cnt+=1
        if(cnt>=maxd):break
        x.append(float(row[0]))  # 第一列為 X 座標
        y.append(float(row[1]))  # 第二列為 Y 座標

with open('F_I_star_data.csv', newline='') as csvfile:
    # 讀取 CSV 檔案內容
    data = csv.reader(csvfile)
    # 提取 X 和 Y 座標
    mx = []
    my = []
    cnt=0
    for row in data:
        cnt+=1
        if(cnt>=maxd):break
        mx.append(float(row[0]))  # 第一列為 X 座標
        my.append(float(row[1]))  # 第二列為 Y 座標

# 生成一些隨機數據
# x = np.linspace(0, 10, 100)
# y = np.sin(x)
xx=[]
yy=[]
for i in range(3,len(mx)+3) :
    xx.append(i)
    yy.append(i-1)
# 創建一個子圖
fig, ax = plt.subplots()
ax.plot(x, y,marker='.',markersize=0.1,color='red')
line, = ax.plot(mx, my,color='blue')
ax.plot(xx, yy,color="red")
# plt.scatter(mx,my,s=1,c='blue')
# plt.scatter(x,y,s=1,c='red')
# plt.scatter(xx,yy,s=1,c='red')
ax.set_xlim(min(x), max(x))
ax.set_ylim(min(y), max(y))

# 定義放大和縮小函數
def zoom(event):
    axtemp=event.inaxes
    x_min, x_max = axtemp.get_xlim()
    xrang = (x_max - x_min) / 100
    y_min, y_max = axtemp.get_ylim()
    yrang = (y_max - y_min) / 100
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
