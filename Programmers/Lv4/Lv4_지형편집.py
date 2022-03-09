def solution(land, P, Q):
    answer = -1
    N = len(land)
    v = []
    for i in range(N):
        for j in range(N):
            v.append(land[i][j])
    v.sort()            # ?믪씠 ?쒖쑝濡??뺣젹

    temp = 0
    for i in range(len(v)):
        temp += (v[i]-v[0])*Q       # 媛???뀁? ?믪씠 湲곗??쇰줈 留욎텧 ??湲덉븸 怨꾩궛
    answer = temp

    for i in range(1, len(v)):
        down = i             # i踰덉㎏ 釉붾윮
        up = len(v) - i      # i踰덉㎏ 釉붾윮 ?댄썑濡??⑥? 釉붾윮 媛?닔
        temp += down*(v[i]-v[i-1])*P        # v[i]濡?留뚮뱾湲??꾪븳 釉붾윮 異붽? 鍮꾩슜
        temp -= up*(v[i] - v[i-1])*Q        # v[i]濡?留뚮뱾湲??꾪븳 釉붾윮 ?쒓굅 鍮꾩슜 諛섑솚
        if answer > temp:
            answer = temp
    return answer