def solution(priorities, location):
    answer = 0

    temp = max(priorities)
    while True:
        top = priorities.pop(0)
        if top == temp:  # 프린트 가능
            answer += 1
            if location == 0:  # 찾았다!
                break
            else:
                location -= 1
            temp = max(priorities)
        else:  # 프린트 불가능
            priorities.append(top)
            if location == 0:
                location = len(priorities) - 1
            else:
                location -= 1

    return answer