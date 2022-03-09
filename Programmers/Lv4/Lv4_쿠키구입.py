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
            if total % 2 != 0:  # 荑좏궎媛 ??섍컻?대㈃ ?⑥뒪
                continue
            if total // 2 < answer:  # ?섎닠 媛?몃룄 ?댁쟾 ?듬낫???묒쓣 寃쎌슦 ?⑥뒪
                continue
            for index in range(end, start, -1):
                if sum[index] - sum[start] == total // 2:
                    if total // 2 > answer:
                        answer = total // 2
                    break
                elif sum[index] - sum[start] < total // 2:
                    break
    return answer