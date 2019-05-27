def solution(land, P, Q):
    answer = -1
    N = len(land)
    v = []
    for i in range(N):
        for j in range(N):
            v.append(land[i][j])
    v.sort()            # 높이 순으로 정렬

    temp = 0
    for i in range(len(v)):
        temp += (v[i]-v[0])*Q       # 가장 낲은 높이 기준으로 맞출 때 금액 계산
    answer = temp

    for i in range(1, len(v)):
        down = i             # i번째 블럭
        up = len(v) - i      # i번째 블럭 이후로 남은 블럭 갯수
        temp += down*(v[i]-v[i-1])*P        # v[i]로 만들기 위한 블럭 추가 비용
        temp -= up*(v[i] - v[i-1])*Q        # v[i]로 만들기 위한 블럭 제거 비용 반환
        if answer > temp:
            answer = temp
    return answer