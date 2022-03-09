def search(cost, check):
    end = 0
    temp = 500001
    for i in range(1, len(cost)):
        if check[i] == False and cost[i] < temp:        # 媛???묒? 鍮꾩슜???쒕뒗 留덉쓣 踰덊샇
            temp = cost[i]
            end = i
    return end

def solution(N, road, K):
    answer = 0

    graph = [[500001 for col in range(N+1)] for row in range(N+1)]  # 鍮꾩슜 ?뺣낫
    cost = [500001] * (N + 1)
    check = [False] * (N + 1)
    cost[1] = 0  # 1踰?吏??? 0?쇰줈 珥덇린??

    for i in range(len(road)):
        if graph[road[i][0]][road[i][1]] == 500001:
            graph[road[i][0]][road[i][1]] = road[i][2]
            graph[road[i][1]][road[i][0]] = road[i][2]
        else:
            if graph[road[i][0]][road[i][1]] > road[i][2]:
                graph[road[i][0]][road[i][1]] = road[i][2]
                graph[road[i][1]][road[i][0]] = road[i][2]

    for i in range(1,N+1):
        end = search(cost,check)        # 媛??媛源뚯슫 留덉쓣 李얘린
        for j in range(1, N+1):
            cost[j] = min(cost[j], cost[end] + graph[end][j])
        check[end] = True

    for i in range(1,len(cost)):
        if cost[i] <= K:
            answer += 1
    return answer

print(solution(5,[[1,2,1],[2,3,3],[5,2,2],[1,4,2],[5,3,1],[5,4,2]],3))