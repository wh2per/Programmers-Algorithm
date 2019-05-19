ans = -1

def go(N, number, result, count):
    global ans
    if count > 8:       # 종료조건
        return
    if number == result:    # 완료조건
        if count < ans or ans == -1:
            ans = count
        return
    nn = 0
    for i in range(0,8):
        nn = nn * 10 + N
        go(N, number, result + nn, count + 1 + i)
        go(N, number, result - nn, count + 1 + i)
        go(N, number, result * nn, count + 1 + i)
        go(N, number, result // nn, count + 1 + i)


def solution(N, number):
    go(N,number,0,0)
    return ans
print(solution(5,12))