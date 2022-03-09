def solution(citations):
    answer = 0
    citations.sort(reverse=True)
    for i in range(len(citations)):
        if i+1 > citations[i]:    # 泥섏쓬?쇰줈 ?섎뒗 ?몃뜳?ㅺ? ?섏삤硫?
            return i              # ?댁쟾 ?몃뜳??諛섑솚
    return len(citations)

print(solution([0, 1, 3, 5, 6]))