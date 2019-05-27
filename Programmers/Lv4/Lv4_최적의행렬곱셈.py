def solution(matrix_sizes):
    m = [[0 for x in range(len(matrix_sizes) + 1)] for y in range(len(matrix_sizes) + 1)]
    d = [matrix_sizes[0][0]]

    for i in range(len(matrix_sizes)):
        d.append(matrix_sizes[i][1])

    for q in range(len(matrix_sizes)):
        for i in range(1, len(matrix_sizes)-q+1):
            j = i + q
            if j == i:
                m[i][j] = 0
                continue
            m[i][j] = 9999999999
            for k in range(i,j):
                m[i][j] = min(m[i][j], m[i][k] + m[k+1][j] + (d[i-1] * d[k] * d[j]))
    return m[1][len(matrix_sizes)]

print(solution(	[[5, 3], [3, 10], [10, 6]]))