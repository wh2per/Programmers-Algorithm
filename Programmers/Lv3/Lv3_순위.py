def solution(n, results):
    answer = 0
    win = [[] for x in range(n+1)]
    lose = [[] for x in range(n+1)]

    for i in results:
        win[i[0]].append(i[1])
        lose[i[1]].append(i[0])

    for i in range(2):              # 2踰?諛섎났
        for j in range(1, n+1):     # ?섑븳??吏???щ엺???낅뜲?댄듃
            for k in lose[j]:
                for h in lose[k]:
                    if h not in lose[j]:
                        lose[j].append(h)

        for j in range(1, n+1):     # ?섑븳???닿릿 ?щ엺???낅뜲?댄듃
            for k in win[j]:
                for h in win[k]:
                    if h not in win[j]:
                        win[j].append(h)

    for i in range(1,n+1):
        if len(lose[i]) + len(win[i]) >= n-1:
            answer += 1
    return answer

print(solution(5,[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))