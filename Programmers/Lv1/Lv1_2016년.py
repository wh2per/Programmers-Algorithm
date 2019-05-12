def solution(a, b):
    answer = ''
    v = ["SUN","MON","TUE","WED","THU","FRI","SAT"]
    index = 0
    if a == 1 or a == 4 or a == 7:
        index = 5
    elif a == 2 or a == 8:
        index = 1
    elif a == 3 or a == 11:
        index = 2
    elif a == 5:
        index = 0
    elif a == 6:
        index = 3
    elif a == 9 or a == 12:
        index = 4
    elif a == 10:
        index = 6

    index += b % 7;
    if index > 6:
        index -= 7

    if index == 0:
        index = 6
    else:
        index -= 1
    return v[index]

print(solution(5,24))