def solution(weight):
    answer = 1
    weight.sort()

    for i in weight:
        if answer < i:      # 누적된 값보다 크면 만들수 없는 무게임
            break
        answer += i
    return answer