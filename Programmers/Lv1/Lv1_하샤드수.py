def solution(x):
    s = str(x)
    num = 0
    for i in s:
        num += int(i)

    if x % num == 0:
        return True
    else:
        return False