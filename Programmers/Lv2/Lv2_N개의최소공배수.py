import fractions
def solution(arr):
    answer = arr[0]
    for i in arr:
        answer = i * answer / fractions.gcd(i, answer)
    return answer
