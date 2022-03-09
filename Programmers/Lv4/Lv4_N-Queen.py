arr = [[False for x in range(13)] for y in range(13)]
check_col = [False for x in range(13)]
check_dig = [False for x in range(26)]
check_dig2 = [False for x in range(26)]

def check(row, col, n):
    if check_col[col]:      # |
        return False
    if check_dig[row+col]:  # ?쇱そ???媛곸꽑
        return False
    if check_dig2[row-col+n]:   # /
        return False
    return True

def calc(n, row):
    if row == n:
        return 1
    cnt = 0
    for col in range(n):
        if check(row, col, n):
            check_dig[row+col] = True
            check_dig2[row-col+n] = True
            check_col[col] = True
            arr[row][col] = True
            cnt += calc(n, row+1)
            check_dig[row + col] = False
            check_dig2[row - col + n] = False
            check_col[col] = False
            arr[row][col] = False
    return cnt

def solution(n):
    return calc(n,0)