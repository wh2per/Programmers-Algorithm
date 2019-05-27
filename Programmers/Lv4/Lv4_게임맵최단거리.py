def solution(maps):
    answer = 0
    ey = len(maps)
    ex = len(maps[0])
    q = [[0, 0]]

    while q:
        answer += 1
        size = len(q)
        for j in range(size):
            top = q.pop(0)
            x = top[1]
            y = top[0]
            if maps[y][x] == 0:
                continue
            if x == ex - 1 and y == ey - 1:
                return answer
            maps[y][x] = 0

            if x + 1 < ex and maps[y][x + 1] == 1:
                q.append([y, x + 1])
            if x - 1 > -1 and maps[y][x - 1] == 1:
                q.append([y, x - 1])
            if y + 1 < ey and maps[y + 1][x] == 1:
                q.append([y + 1, x])
            if y - 1 > -1 and maps[y - 1][x] == 1:
                q.append([y - 1, x])
    return -1

print(solution(	[[1, 0, 1, 1, 1], [1, 0, 1, 0, 1], [1, 0, 1, 1, 1], [1, 1, 1, 0, 1], [0, 0, 0, 0, 1]]))