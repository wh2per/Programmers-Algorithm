import heapq

def solution(stock, dates, supplies, k):
    answer = 0
    for i in dates[::-1]:       # dates를 역순으로 순회
        if i > k:               # k보다 크다면 불필요하므로 제거!
            dates.pop()
            supplies.pop()
        else:
            break
    dates.append(k)             # 최종날을 삽입
    dates.pop(0)
    heap = [-supplies[0]]       # 처음 생산량을 힙에 저장
    heapq.heapify(heap)
    for index, day in enumerate(dates):     # 인덱스와 날짜를 추출하여 순회
        while stock < day:                    # 현재량이 day보다 작으면 공급받아야함
            stock += -heapq.heappop(heap)       # 최대값을 공급받음
            answer += 1
        if day != k:                    # 최종날에 도달하지 않았다면
            heapq.heappush(heap, -supplies[index + 1])      # heap에 추가
    return answer
print(solution( 4, [1, 2, 3, 4], [10, 40, 30, 20], 100))