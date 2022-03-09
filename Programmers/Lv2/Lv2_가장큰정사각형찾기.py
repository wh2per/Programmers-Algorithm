def solution(board):
    answer = 0
    xlen = len(board[0])
    ylen = len(board)

    if xlen < 2 or ylen < 2:        # 媛濡? ?몃줈 以??섎굹?쇰룄 湲몄씠媛 1?대씪硫?
        for i in range(ylen):
            for j in range(xlen):
                if board[i][j] == 1:
                    answer = 1
    else:
        for i in range(1,ylen):
            for j in range(1,xlen):
                if board[i][j] == 1:
                    board[i][j] = min(board[i][j - 1], board[i - 1][j], board[i - 1][j - 1]) + 1
                    if answer < board[i][j]:
                        answer = board[i][j]
    return answer * answer