def solution(progresses, speeds):
    answer = []
    temp = []
    for i, j in zip(progresses, speeds):
        diff = 100 - i
        count = 0
        if diff%j==0:
            count = diff//j
        else:
            count = (diff//j)+1
        temp.append(count)
    temp.reverse()
    while len(temp)>0:
        t1 = temp[-1]       # 최상위
        t2 = 1              # 1개로 초기화
        temp.pop()          # 제거
        while len(temp)!=0 and temp[-1] <= t1:      # 최상위가 나랑 같거나 작으면 추가
            temp.pop()
            t2 += 1
        answer.append(t2)
    return answer

print(solution(	[93, 30, 55], [1, 30, 5]))