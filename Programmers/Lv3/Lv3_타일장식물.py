def solution(N):
    d = [0]*(N*2)
    d[1] = 1
    d[2] = 1
    for i in range(3,N+2):
        d[i] = d[i-2] + d[i-1]
    return d[N]*2 + d[N+1]*2

print(solution(5))