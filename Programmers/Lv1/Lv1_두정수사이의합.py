def solution(a, b):
    if a>b:
        return sum(range(b,a+1))
    else:
        return sum(range(a, b + 1))

print(solution(3,5))