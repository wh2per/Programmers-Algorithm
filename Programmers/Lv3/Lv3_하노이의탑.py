answer = []

def move(n, f, b, t):
    global answer
    if n == 1:
        answer.append([f, t])
    else:
        move(n - 1, f, t, b)        # to를 임시저장소로 이용하여 from에서 by로
        answer.append([f, t])
        move(n - 1, b, f, t)        # from을 임시저장소로 이용하여 by에서 to로

def solution(n):
    move(n, 1, 2, 3)
    return answer