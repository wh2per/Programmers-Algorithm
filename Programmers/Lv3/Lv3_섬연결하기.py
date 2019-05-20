# 프림알고리즘(앞 단계에서 만들어진 신장 트리 집합에 인접한 정점들 중에서 최소 간선으로 연결된 정점을 선택하여 트리를 확장)
import operator

def isEnd(check, n):
    for i in range(n):
        if check[i] == False:
            return False
    return True

def solution(n, costs):
    answer = 0
    check = [False]*101

    check[costs[0][0]] = True       # 시작지점 True

    while not isEnd(check,n):
        island = []
        for i in range(n):
            if check[i]:        # 검사할 정점
                for j in costs:
                    if (j[0] == i and check[j[1]] == False) or (j[1] == i and check[j[0]] == False):    # 아직 안 사용한 간선일 때
                        island.append(j)

        island.sort(key=operator.itemgetter(2))
        temp = island[0]
        answer += temp[2]
        check[temp[0]] = True
        check[temp[1]] = True
        costs.remove(temp)

    return answer

print(solution(4, [[0, 1, 1], [0, 2, 2], [1, 2, 5], [1, 3, 1], [2, 3, 8]]))     # 4