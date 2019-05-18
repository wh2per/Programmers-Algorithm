import itertools

def solution(numbers):
    s = set()
    number = list(numbers)
    count = len(numbers)
    number.sort()
    for i in range(1, count + 1):
        for nums in itertools.permutations(number, i):
            temp = int(''.join(nums))
            s.add(temp)
    n = max(s)
    check = [False] * (n + 1);
    check[0] = check[1] = True;

    for i in range(2, n + 1):
        if check[i] == False:
            for j in range(i * i, n + 1, i):
                check[j] = True
    answer = 0
    for i in s:
        if check[i]==False:
            answer += 1

    return answer
