def solution(n):
    answer = 0
    end = str(n)
    for i in end:
        answer += int(i)
    return answer