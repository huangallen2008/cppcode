# def get_grade(score):
#     if not isinstance(score, (int, float)) or score < 0 or score > 100:
#         return 'Invalid score'
#     if 90 <= score <= 100:
#             return '優'
#     elif 80 <= score < 90:
#         return '甲'
#     elif 70 <= score < 80:
#         return '乙'
#     elif 60 <= score < 70:
#         return '丙'
#     elif 50 <= score < 60:
#         return '丁'
#     elif 40 <= score < 50:
#         return '不及格'
#     else:
#         return '掰掰你被死當了'
try:
    w = list(map(float,input().split(' ')))
    w = list(map(float,input().split(' ')))

except ValueError:
    print("輸入的不是有效的數字。")