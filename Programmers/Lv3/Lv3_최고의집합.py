def solution(n, s):
    answer = []
    if n>s:
        answer.append(-1)
    elif n==s:
        for i in range(0,n):
            answer.append(1)
    else:
        q = s//n
        r = s%n
        j = n-1
        for i in range(n):
            answer.append(q)
        while r!=0:
            answer[j] += 1
            j -= 1
            r -= 1
    return answer