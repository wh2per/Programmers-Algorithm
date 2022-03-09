def solution(n):
    answer = ''
    arr = [1, 2, 4]
    r = -1

    while n > 0:
        n -= 1
        r = n % 3
        answer += str(arr[n % 3])
        n = n // 3

    answer = answer[::-1]

    return answer