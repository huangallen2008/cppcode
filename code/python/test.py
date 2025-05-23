import numpy as np

# 給定的數據
X = np.array([5, 4, 3, 2, 1])
y = np.array( [1, 2, 3, 4, 5])

# 計算 x 和 y 的均值
x_mean = np.mean(X)
y_mean = np.mean(y)

# 計算 m（斜率）
m = np.sum((X - x_mean) * (y - y_mean)) / np.sum((X - x_mean)**2)

# 計算 b（截距）
b = y_mean - m * x_mean

# 顯示結果
print(f"斜率 (m): {m}")
print(f"截距 (b): {b}")

# 使用封閉解進行預測
def predict(x):
    return m * x + b

# 測試預測
predictions = predict(X)
print(f"預測結果: {predictions}")