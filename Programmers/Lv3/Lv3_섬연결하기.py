# ?꾨┝?뚭퀬由ъ쬁(???④퀎?먯꽌 留뚮뱾?댁쭊 ?좎옣 ?몃━ 吏묓빀???몄젒???뺤젏??以묒뿉??理쒖냼 媛꾩꽑?쇰줈 ?곌껐???뺤젏???좏깮?섏뿬 ?몃━瑜??뺤옣)
import operator

def isEnd(check, n):
    for i in range(n):
        if check[i] == False:
            return False
    return True

def solution(n, costs):
    answer = 0
    check = [False]*101

    check[costs[0][0]] = True       # ?쒖옉吏??True

    while not isEnd(check,n):
        island = []
        for i in range(n):
            if check[i]:        # 寃?ы븷 ?뺤젏
                for j in costs:
                    if (j[0] == i and check[j[1]] == False) or (j[1] == i and check[j[0]] == False):    # ?꾩쭅 ???ъ슜??媛꾩꽑????
                        island.append(j)

        island.sort(key=operator.itemgetter(2))
        temp = island[0]
        answer += temp[2]
        check[temp[0]] = True
        check[temp[1]] = True
        costs.remove(temp)

    return answer

print(solution(4, [[0, 1, 1], [0, 2, 2], [1, 2, 5], [1, 3, 1], [2, 3, 8]]))     # 4