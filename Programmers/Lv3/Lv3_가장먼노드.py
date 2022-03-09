def solution(n, edge):
    answer = 0
    graph = [set() for x in range(n+1)]
    dist = [0] * (n+1)
    check = [False] * (n+1)
    q = []

    for i in edge:                      # ?곌껐 ?뺣낫 ???
        graph[i[0]].add(i[1])
        graph[i[1]].add(i[0])

    q.append(1)
    check[1] = True
    dist[1] = 0

    while q:
        start = q.pop(0)
        for i in graph[start]:
            if not check[i]:
                check[i] = True
                dist[i] = dist[start] + 1
                q.append(i)

    inf = max(dist)                 # 媛??癒?嫄곕━
    for i in range(1, n+1):
        if dist[i] == inf:
            answer += 1
    return answer

print(solution(6, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))        # 3