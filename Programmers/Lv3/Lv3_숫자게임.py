def solution(A, B):
    answer = 0
    A.sort()
    B.sort()
    save = 0

    for i in range(len(A)):
        for j in range(save, len(B)):
            if A[i] < B[j]:
                answer += 1
                save = j
                save += 1
                break

    return answer