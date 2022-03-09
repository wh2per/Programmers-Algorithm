def solution(s):
    a = list()

    for i in s:
        if len(a)>0 and a[-1] == i:
            a.pop()
        else:
            a.append(i)

    if len(a) == 0:
        return 1
    else:
        return 0


print(solution("baabaa"))