def solution(n, results):
    answer = 0
    win = [[] for x in range(n+1)]
    lose = [[] for x in range(n+1)]

    for i in results:
        win[i[0]].append(i[1])
        lose[i[1]].append(i[0])

    for i in range(2):              # 2번 반복
        for j in range(1, n+1):     # 나한테 지는 사람을 업데이트
            for k in lose[j]:
                for h in lose[k]:
                    if h not in lose[j]:
                        lose[j].append(h)

        for j in range(1, n+1):     # 나한테 이긴 사람을 업데이트
            for k in win[j]:
                for h in win[k]:
                    if h not in win[j]:
                        win[j].append(h)

    for i in range(1,n+1):
        if len(lose[i]) + len(win[i]) >= n-1:
            answer += 1
    return answer

print(solution(5,[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))