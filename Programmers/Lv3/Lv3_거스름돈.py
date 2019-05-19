def solution(n, money):
    d = [0]*(n+1)
    d[0] = 1

    for i in money:
        for j in range(i,n+1):
            d[j] = (d[j] + d[j-i])%1000000007
    return d[n]

print(solution(5,[1,2,5]))