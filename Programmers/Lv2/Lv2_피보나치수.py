def solution(n):
    d = [0,1]
    for i in range(2,n+1):
        d.append((d[i-2] + d[i-1])%1234567)
    return d[n]