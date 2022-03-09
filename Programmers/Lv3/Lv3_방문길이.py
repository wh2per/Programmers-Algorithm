dy = [0,1,0,-1]
dx = [1,0,-1,0]

def solution(dirs):
    global dy
    global dx
    answer = 0
    visited = []

    start = [0,0]
    for i in dirs:
        if i == 'U':
            if [start,3] not in visited:
                visited.append([start,3])
            start = [start[0]+dy[1], start[1]+dx[1]]
            if -5 > start[0] or start[0] > 5 or start[1] >5 or start[1] < -5:
                start = [start[0] - dy[1], start[1] - dx[1]]
                continue
            if [start,1] not in visited:
                visited.append([start,1])
                answer += 1
        elif i == 'R':
            if [start,2] not in visited:
                visited.append([start,2])
            start = [start[0] + dy[0], start[1] + dx[0]]
            if -5 > start[0] or start[0] > 5 or start[1] >5 or start[1] < -5:
                start = [start[0] - dy[0], start[1] - dx[0]]
                continue
            if [start, 0] not in visited:
                visited.append([start, 0])
                answer += 1
        elif i == 'D':
            if [start,1] not in visited:
                visited.append([start,1])
            start = [start[0] + dy[3], start[1] + dx[3]]
            if -5 > start[0] or start[0] > 5 or start[1] >5 or start[1] < -5:
                start = [start[0] - dy[3], start[1] - dx[3]]
                continue
            if [start, 3] not in visited:
                visited.append([start, 3])
                answer += 1
        elif i == 'L':
            if [start,0] not in visited:
                visited.append([start,0])
            start = [start[0] + dy[2], start[1] + dx[2]]
            if -5 > start[0] or start[0] > 5 or start[1] >5 or start[1] < -5:
                start = [start[0] - dy[2], start[1] - dx[2]]
                continue
            if [start, 2] not in visited:
                visited.append([start, 2])
                answer += 1

    return answer

print(solution("LURDLLURD"))