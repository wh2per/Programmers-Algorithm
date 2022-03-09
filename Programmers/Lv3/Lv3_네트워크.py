net = [[0]*201 for i in range(201)]
check = [False]*201

def dfs(x, n):
    global net
    global check

    check[x] = 1

    for i in range(n):
        if net[x][i] == 1 and check[i] != 1:
            dfs(i, n)

def solution(n, computers):
    answer = 0
    global check

    for i in range(n):
        for j in range(n):
            if computers[i][j] == 1:
                net[i][j] = 1

    for i in range(n):
        if check[i] != 1:
            dfs(i, n)
            answer += 1

    return answer

print(solution(3, [[1, 1, 0], [1, 1, 0], [0, 0, 1]]))