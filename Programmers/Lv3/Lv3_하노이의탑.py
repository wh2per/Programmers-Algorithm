answer = []

def move(n, f, b, t):
    global answer
    if n == 1:
        answer.append([f, t])
    else:
        move(n - 1, f, t, b)        # to瑜??꾩떆??μ냼濡??댁슜?섏뿬 from?먯꽌 by濡?
        answer.append([f, t])
        move(n - 1, b, f, t)        # from???꾩떆??μ냼濡??댁슜?섏뿬 by?먯꽌 to濡?

def solution(n):
    move(n, 1, 2, 3)
    return answer