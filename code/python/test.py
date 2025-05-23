try:
    weights_input = input()
    scores_input = input()

    weights = list(map(float, weights_input.split()))
    scores = list(map(int, scores_input.split()))

    if len(weights) != 5 or len(scores) != 5:
        print("輸入的成績數量不符合科目數量。")
    elif not all(0 <= score <= 100 for score in scores):
        print("成績應在0到100之間。")
    else:
        total = sum(w * s for w, s in zip(weights, scores))
        total_rounded = round(total , 2) 
        print(f"{total_rounded:.2f}")

        if total_rounded >= 90:
            grade = 'A+'
        elif total_rounded >= 85:
            grade = 'A'
        elif total_rounded >= 80:
            grade = 'B+'
        elif total_rounded >= 75:
            grade = 'B'
        elif total_rounded >= 70:
            grade = 'C+'
        elif total_rounded >= 65:
            grade = 'C'
        elif total_rounded >= 60:
            grade = 'D'
        else:
            grade = 'F'
        print(grade)
except ValueError:
    print("輸入的不是有效的數字。")
