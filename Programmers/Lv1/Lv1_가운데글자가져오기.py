def solution(s):
    answer = ''
    if(len(s)%2==0):        # 길이가 짝수
        cut = int(len(s)/2 -1)
        answer = s[cut:cut+2]
    else:               # 길이가 홀수
        cut = int((len(s)-1) / 2)
        answer = s[cut:cut + 1]

    return answer

print(solution("abcde"))