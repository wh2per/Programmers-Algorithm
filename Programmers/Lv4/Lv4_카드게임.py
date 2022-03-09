def solution(left, right):
    d = [[0 for x in range(len(left)+1)] for y in range(len(left)+1)]       # 0?쇰줈 珥덇린??-> i : ?쇱そ移대뱶, j : ?ㅻⅨ履쎌뭅??
    for i in range(len(left)+1):
        d[0][i] = -1

    for i in range(1, len(left)+1):
        for j in range(1, len(left)+1):
            d[i][j] = max(d[i-1][j], d[i-1][j-1])           # ?쇱そ留?踰꾨┫?? ?묒そ紐⑤몢 踰꾨┫??以묒뿉 ?곌컪
            if d[i][j-1] != -1 and left[i-1] > right[j-1]:  # ?ㅻⅨ履쎄컪?????묒쓣??
                d[i][j] = d[i][j-1] + right[j-1]
    return d[len(left)][len(left)]

print(solution([3, 2, 5], [2, 4, 1]))