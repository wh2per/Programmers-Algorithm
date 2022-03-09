import operator
import functools

def cmp(a,b):
    if a[1] > b[1]:
        return -1
    elif a[1] == b[1]:
        if a[2] < b[2]:
            return -1
        else:
            return 1
    else:
        return 1

def solution(genres, plays):
    answer = []
    total = dict()
    info = []
    for i in range(len(genres)):
        if genres[i] in total:
            total[genres[i]] += plays[i]
        else:
            total[genres[i]] = plays[i]
        info.append([genres[i], plays[i], i])

    totalArr = sorted(total.items(), key=operator.itemgetter(1), reverse=True)

    for i in totalArr:
        temp = []
        for j in info:
            if j[0] == i[0]:
                temp.append(j)
        tempArr = sorted(temp, key=functools.cmp_to_key(cmp))
        if len(tempArr) > 1:
            for j in range(2):
                answer.append(tempArr[j][2])
        else:
            answer.append(tempArr[0][2])

    return answer

print(solution(	["classic", "pop", "classic", "classic", "pop"], [150, 600, 150, 150, 2500]))
#	[4, 1, 3, 0]