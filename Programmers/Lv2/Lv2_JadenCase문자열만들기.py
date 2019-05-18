def solution(s):
    answer = ''
    flag = True
    for i in s:
        if flag and not i.isdigit():
            answer += i.upper()
            flag = False
        else:
            answer += i.lower()
            flag = False

        if i.isspace():
            flag = True
    return answer

print(solution("332people                     #unFollowed m3e   "))