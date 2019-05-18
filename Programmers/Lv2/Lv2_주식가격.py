def solution(prices):
    answer = []

    for i in range(0, len(prices) - 1):
        count = 0
        for j in range(i + 1, len(prices)):
            count += 1
            if prices[i] > prices[j]:
                break
        answer.append(count)
    answer.append(0)
    return answer