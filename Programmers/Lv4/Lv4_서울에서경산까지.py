def solution(K, travel):
    d = [0 for x in range(100001)]

    for i in range(len(travel)):            # i번째 경로까지 j분 이하의 시간으로 얻을 수 있는 최대 모금
        for j in range(K, -1, -1):
            d[j] = -999999          # 최소값으로 초기화
            if j >= travel[i][0]:
                d[j] = max(d[j], d[j-travel[i][0]] + travel[i][1])
            if j >= travel[i][2]:
                d[j] = max(d[j], d[j-travel[i][2]] + travel[i][3])

    return d[K]
print(solution(1650,[[500, 200, 200, 100], [800, 370, 300, 120], [700, 250, 300, 90]]))