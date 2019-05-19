def search(cost, check):
    end = 0
    temp = 500001
    for i in range(1, len(cost)):
        if check[i] == False and cost[i] < temp:        # 가장 작은 비용이 드는 마을 번호
            temp = cost[i]
            end = i
    return end

def solution(N, road, K):
    answer = 0

    graph = [[500001 for col in range(N+1)] for row in range(N+1)]  # 비용 정보
    cost = [500001] * (N + 1)
    check = [False] * (N + 1)
    cost[1] = 0  # 1번 지역은 0으로 초기화

    for i in range(len(road)):
        if graph[road[i][0]][road[i][1]] == 500001:
            graph[road[i][0]][road[i][1]] = road[i][2]
            graph[road[i][1]][road[i][0]] = road[i][2]
        else:
            if graph[road[i][0]][road[i][1]] > road[i][2]:
                graph[road[i][0]][road[i][1]] = road[i][2]
                graph[road[i][1]][road[i][0]] = road[i][2]

    for i in range(1,N+1):
        end = search(cost,check)        # 가장 가까운 마을 찾기
        for j in range(1, N+1):
            cost[j] = min(cost[j], cost[end] + graph[end][j])
        check[end] = True

    for i in range(1,len(cost)):
        if cost[i] <= K:
            answer += 1
    return answer

print(solution(5,[[1,2,1],[2,3,3],[5,2,2],[1,4,2],[5,3,1],[5,4,2]],3))