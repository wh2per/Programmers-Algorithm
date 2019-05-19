def solution(n, stations, w):
    answer = 0
    index = 1

    size = 2*w+1
    for i in stations:
        answer += (i-w-index)//size
        if (i-w-index)%size != 0:
            answer += 1
        index = i + w + 1
    if n >= index:
        answer += (n + 1 - index) // size
        if (n + 1 - index) % size != 0:
            answer += 1

    return answer

print(solution(	16, [9], 2))