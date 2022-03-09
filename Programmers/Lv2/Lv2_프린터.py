def solution(priorities, location):
    answer = 0

    temp = max(priorities)
    while True:
        top = priorities.pop(0)
        if top == temp:  # ?꾨┛??媛??
            answer += 1
            if location == 0:  # 李얠븯??
                break
            else:
                location -= 1
            temp = max(priorities)
        else:  # ?꾨┛??遺덇???
            priorities.append(top)
            if location == 0:
                location = len(priorities) - 1
            else:
                location -= 1

    return answer