def solution(operations):
    num = []
    for i in operations:
        temp = i.split()
        if temp[0] == 'I':
            num.append(int(temp[1]))
        else:
            if num:
                if temp[1] == '1':
                    num.sort()
                    num.pop()
                else:
                    num.sort()
                    num.pop(0)
    num.sort()
    if num:
        return [num[-1], num[0]]
    else:
        return [0,0]


print(solution(["I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"]))
# [7,5]