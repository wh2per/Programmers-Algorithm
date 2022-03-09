def solution(n):
    num = list(str(n))
    num.sort(reverse=True)

    return int("".join(num))