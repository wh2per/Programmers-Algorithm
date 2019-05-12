def solution(n, lost, reserve):
    answer = 0
    for i in range(1, n + 1):
        if i not in lost:  # 안 잃어버린 학생
            answer += 1
        else:
            if i in reserve:  # 잃어버렸지만 여분도 있는 학생
                answer += 1
                reserve.remove(i)
                lost.remove(i)

    for i in lost:  # 잃어버리고 여분도 없어서 빌려야 하는 학생
        if i - 1 in reserve:
            answer += 1
            reserve.remove(i - 1)

        elif i + 1 in reserve:
            answer += 1
            reserve.remove(i + 1)
    return answer

print(solution(5,[2,4],[3]))