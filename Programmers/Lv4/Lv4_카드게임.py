def solution(left, right):
    d = [[0 for x in range(len(left)+1)] for y in range(len(left)+1)]       # 0으로 초기화 -> i : 왼쪽카드, j : 오른쪽카드
    for i in range(len(left)+1):
        d[0][i] = -1

    for i in range(1, len(left)+1):
        for j in range(1, len(left)+1):
            d[i][j] = max(d[i-1][j], d[i-1][j-1])           # 왼쪽만 버릴때, 양쪽모두 버릴때 중에 큰값
            if d[i][j-1] != -1 and left[i-1] > right[j-1]:  # 오른쪽값이 더 작을때
                d[i][j] = d[i][j-1] + right[j-1]
    return d[len(left)][len(left)]

print(solution([3, 2, 5], [2, 4, 1]))