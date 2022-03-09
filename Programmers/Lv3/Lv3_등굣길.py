def solution(m, n, puddles):
    road = [[0 for col in range(m+1)] for row in range(n+1)]
    check = [[0 for col in range(m+1)] for row in range(n+1)]

    for i in puddles:
        check[i[1]][i[0]] = -1

    road[1][0] = 1
    for i in range(1, n+1):
        for j in range(1, m+1):
            if check[i][j] == -1:
                road[i][0] = 0
            else:
                road[i][j] = (road[i][j-1] + road[i-1][j]) % 1000000007

    return road[n][m]

print(solution(4, 3, [[2, 2]]))