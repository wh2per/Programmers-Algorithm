def solution(arr):
    answer = []
    prev = -1

    for a in arr:
        if prev != a:
            answer.append(a)
            prev = a;
    return answer

print(solution([4,4,4,3,3]))