import heapq

def solution(n, works):
    answer = 0
    heap = []
    for i in works:
        heapq.heappush(heap,-i)

    for i in range(0,n):
        a = heapq.heappop(heap)

        if a == 0:
            heapq.heappush(heap,0)
        else:
            heapq.heappush(heap, a+1)

    while heap:
        a = heapq.heappop(heap)
        answer += a*a
    return answer

print(solution(4,[4, 3, 3]))