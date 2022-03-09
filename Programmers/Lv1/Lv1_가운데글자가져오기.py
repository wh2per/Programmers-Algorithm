def solution(s):
    answer = ''
    if(len(s)%2==0):        # 湲몄씠媛 吏앹닔
        cut = int(len(s)/2 -1)
        answer = s[cut:cut+2]
    else:               # 湲몄씠媛 ???
        cut = int((len(s)-1) / 2)
        answer = s[cut:cut + 1]

    return answer

print(solution("abcde"))