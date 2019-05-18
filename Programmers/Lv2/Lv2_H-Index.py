def solution(citations):
    answer = 0
    citations.sort(reverse=True)
    for i in range(len(citations)):
        if i+1 > citations[i]:    # 처음으로 넘는 인덱스가 나오면
            return i              # 이전 인덱스 반환
    return len(citations)

print(solution([0, 1, 3, 5, 6]))