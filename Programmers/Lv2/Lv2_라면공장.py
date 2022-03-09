import heapq

def solution(stock, dates, supplies, k):
    answer = 0
    for i in dates[::-1]:       # dates瑜???닚?쇰줈 ?쒗쉶
        if i > k:               # k蹂대떎 ?щ떎硫?遺덊븘?뷀븯誘濡??쒓굅!
            dates.pop()
            supplies.pop()
        else:
            break
    dates.append(k)             # 理쒖쥌?좎쓣 ?쎌엯
    dates.pop(0)
    heap = [-supplies[0]]       # 泥섏쓬 ?앹궛?됱쓣 ?숈뿉 ???
    heapq.heapify(heap)
    for index, day in enumerate(dates):     # ?몃뜳?ㅼ? ?좎쭨瑜?異붿텧?섏뿬 ?쒗쉶
        while stock < day:                    # ?꾩옱?됱씠 day蹂대떎 ?묒쑝硫?怨듦툒諛쏆븘?쇳븿
            stock += -heapq.heappop(heap)       # 理쒕?媛믪쓣 怨듦툒諛쏆쓬
            answer += 1
        if day != k:                    # 理쒖쥌?좎뿉 ?꾨떖?섏? ?딆븯?ㅻ㈃
            heapq.heappush(heap, -supplies[index + 1])      # heap??異붽?
    return answer
print(solution( 4, [1, 2, 3, 4], [10, 40, 30, 20], 100))