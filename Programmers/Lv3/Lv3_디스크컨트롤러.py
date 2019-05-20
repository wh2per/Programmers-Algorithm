import operator

# SRF 스케쥴링 구현!
def solution(jobs):
    answer = 0
    pq_len = []
    pq_arrive = []

    for i in jobs:
        pq_arrive.append(i)
    pq_arrive.sort(key=operator.itemgetter(0))      # 가장 빨리 도착한 작업 순으로 정렬
    time = pq_arrive[0][0]                          # 가장 빨리 도착한 작업의 시간
    pq_len.append(pq_arrive.pop(0))                 # 작업길이 순으로 정렬할 배열에 추가

    while pq_len or pq_arrive:                      # 두 배열 중 하나라도 작업이 남아있으면
        if pq_arrive and time >= pq_arrive[0][0]:   # 현재 시간보다 도착한 시간이 빠르다면
            pq_len.append(pq_arrive.pop(0))         # 작업길이 순으로 정렬할 배열에 추가
            pq_len.sort(key=operator.itemgetter(1))
        elif pq_len:                                # 아직 다른 작업이 도착하지 않았을 때
            arrive = pq_len[0][0]
            length = pq_len[0][1]
            answer += length                        # 작업시간을 answer에 추가
            if time < arrive:                       # 도착시간 보다 이른 시간이라면
                time = arrive
            answer += time-arrive                   # 작업을 하기까지 기다린 대기시간을 더하기기
            time += length                          # 현재시간 갱신
            pq_len.pop(0)
        else:
            time = pq_arrive[0][0]                  # 현재시간 갱신
    return answer//len(jobs)

print(solution([[0, 3], [1, 9], [2, 6]]))       # 9