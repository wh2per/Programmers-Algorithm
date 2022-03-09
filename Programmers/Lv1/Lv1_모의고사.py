def solution(answers):
    result = []
    q1 = [1,2,3,4,5]
    q2 = [2,1,2,3,2,4,2,5]
    q3 = [3,3,1,1,2,2,4,4,5,5]
    score = [0]*3

    for idx, ans in enumerate(answers):
        if ans == q1[idx%5]:
            score[0] += 1
        if ans == q2[idx%8]:
            score[1]+= 1
        if ans == q3[idx%10]:
            score[2]+= 1

    for idx,s in enumerate(score):
        if s == max(score):
            result.append(idx+1)
    return result

answers = [1, 2, 3, 4, 5]
print(solution(answers))