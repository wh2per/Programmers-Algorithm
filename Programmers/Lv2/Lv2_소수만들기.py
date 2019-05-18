import itertools

def solution(nums):
    answer = 0
    sums = []
    for sum3 in itertools.combinations(nums, 3):
        sums.append(sum(sum3))

    n = max(sums)
    check = [False] * (n + 1)
    check[0] = check[1] = True
    for i in range(2, n + 1):
        if check[i] == False:
            for j in range(i * i, n + 1, i):
                check[j] = True
    for i in sums:
        if check[i] == False:
            answer += 1

    return answer
