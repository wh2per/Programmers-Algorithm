def solution(n):
    answer = []
    s = reversed(str(n))
    for i in s:
        answer.append(int(i))
    return answer