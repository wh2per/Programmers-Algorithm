def solution(n, m):
    max = 1
    min = m
    answer = []
    for i in range(1,n+1):
        if n%i==0 and m%i==0:
            max = i
    for i in range(n,n*m+1,n):
        if i%n==0 and i%m==0:
            min = i
            break;
    answer.append(max)
    answer.append(min)
    return answer