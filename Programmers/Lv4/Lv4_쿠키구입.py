def solution(cookie):
    answer = 0
    sum = []
    sum.append(0)
    sum.append(cookie[0])
    for i in range(1, len(cookie)):
        sum.append(sum[i] + cookie[i])

    size = len(sum)
    start_sum = 0

    for start in range(size):
        for end in range(size - 1, start, -1):
            total = sum[end] - sum[start]
            if total % 2 != 0:  # 쿠키가 홀수개이면 패스
                continue
            if total // 2 < answer:  # 나눠 가져도 이전 답보다 작을 경우 패스
                continue
            for index in range(end, start, -1):
                if sum[index] - sum[start] == total // 2:
                    if total // 2 > answer:
                        answer = total // 2
                    break
                elif sum[index] - sum[start] < total // 2:
                    break
    return answer