import math

def solution(n, k):
    answer = []
    number = []
    for i in range(1, n+1):
        number.append(i)

    nc = 0
    c = 0
    rest = n-1

    while nc < n:
        if math.factorial(rest) >= k:
            temp = number[c]
            number.pop(c)
            answer.append(temp)
            c = 0
            rest -= 1
            nc += 1
        else:
            c += 1
            k -= math.factorial(rest)

    return answer


print(solution(3,5))        # 3 1 2