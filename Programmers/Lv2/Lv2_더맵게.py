import heapq

def solution(scoville, K):
    heapq.heapify(scoville)
    top = heapq.heappop(scoville)
    if len(scoville) == 0:
        if top > K:
            return 0
        else:
            return -1

    answer = 0
    while scoville:
        if top > K:
            return answer
        next = heapq.heappop(scoville)
        answer += 1
        heapq.heappush(scoville, top + (next * 2))
        top = heapq.heappop(scoville)
    if top > K:
        return answer
    else:
        return -1
