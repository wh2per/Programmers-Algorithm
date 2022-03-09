def solution(n):
    answer = 0
    check = [False] * (n+1);
    check[0] = check[1] = True;

    for i in range(2,n+1):
        if check[i] == False:
            for j in range(i*i, n+1, i):
                check[j] = True

    for i in range(2,n+1):
        if check[i] == False:
            answer += 1

    return answer