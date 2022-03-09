def solution(money):
    answer = 0
    d = [0 for x in range(len(money))]

    # 泥ル쾲吏?吏??멸린
    d[0] = money[0]
    d[1] = money[0]

    for i in range(2, len(money)-1):
        d[i] = max(d[i-2] + money[i], d[i-1])
    answer = d[len(money)-2]

    # 泥ル쾲吏?吏멭 -> ?먮쾲吏?吏묐????멸린
    d[0] = 0
    d[1] = money[1]
    for i in range(2, len(money)):
        d[i] = max(d[i - 2] + money[i], d[i-1])
    answer = max(answer, d[len(money)-1])
    return answer

print(solution([1, 2, 3, 1]))