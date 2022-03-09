def solution(s):
    answer = ''
    index = 0
    for i in s:
        if i != " ":
            if index%2==0:
                answer += i.upper()
            else:
                answer += i.lower()
            index += 1
        else:
            index = 0
            answer += i
    return answer