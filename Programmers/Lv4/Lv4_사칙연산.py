def solution(arr):
    d = [[[0 for x in range(2)] for y in range(201)] for z in range(201)]
    oper = []

    # 숫자로 변환
    for i in range(len(arr)):
        if arr[i] == "+":
            oper.append(1001)
        elif arr[i] == "-":
            oper.append(1002)
        else:
            oper.append(int(arr[i]))
            d[i][i][0] = oper[i]
            d[i][i][1] = oper[i]

    for i in range(2,len(arr),2): # 첫 숫자, 연산자 이후로 끝까지 (숫자, 연산자) 세트로 증가   -> 범위의 종료 지점 설정
        for j in range(0,len(arr)-i,2):    # 처음부터 len-i 길이를 전부 검사                   -> 범위의 시작 시점 부터 종료 지점까지 검사
            tmax = 0
            tmin = 0
            max_n = -9999999
            min_n = 9999999
            for k in range(j+1,i+j,2):          # 연산 시작
                if oper[k] == 1001:        # +
                    tmax = d[j][k - 1][0] + d[k + 1][i + j][0]
                    tmin = d[j][k - 1][1] + d[k + 1][i + j][1]
                    if tmax > max_n:
                        max_n = tmax
                    if tmin < min_n:
                        min_n = tmin
                elif oper[k] == 1002:       # -
                    tmax = d[j][k - 1][0] - d[k + 1][i + j][1]
                    tmin = d[j][k - 1][1] - d[k + 1][i + j][0]
                    if tmax > max_n:
                        max_n = tmax
                    if tmin < min_n:
                        min_n = tmin
            d[j][j + i][0] = max_n
            d[j][j + i][1] = min_n
    return d[0][len(arr) - 1][0]
