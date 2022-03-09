def solution(K, travel):
    d = [0 for x in range(100001)]

    for i in range(len(travel)):            # i踰덉㎏ 寃쎈줈源뚯? j遺??댄븯???쒓컙?쇰줈 ?살쓣 ???덈뒗 理쒕? 紐④툑
        for j in range(K, -1, -1):
            d[j] = -999999          # 理쒖냼媛믪쑝濡?珥덇린??
            if j >= travel[i][0]:
                d[j] = max(d[j], d[j-travel[i][0]] + travel[i][1])
            if j >= travel[i][2]:
                d[j] = max(d[j], d[j-travel[i][2]] + travel[i][3])

    return d[K]
print(solution(1650,[[500, 200, 200, 100], [800, 370, 300, 120], [700, 250, 300, 90]]))