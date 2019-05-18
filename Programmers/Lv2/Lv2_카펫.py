def solution(brown, red):
    answer = []
    for i in range(red, 0, -1):
        if red%i==0:
            width = i
            height = red//i
            if (width+2)*2 + height*2==brown:
                answer.append(width+2)
                answer.append(height+2)
                break
    return answer

print(solution(10,2))