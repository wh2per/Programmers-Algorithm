import operator

# SRF ?ㅼ?伊대쭅 援ы쁽!
def solution(jobs):
    answer = 0
    pq_len = []
    pq_arrive = []

    for i in jobs:
        pq_arrive.append(i)
    pq_arrive.sort(key=operator.itemgetter(0))      # 媛??鍮⑤━ ?꾩갑???묒뾽 ?쒖쑝濡??뺣젹
    time = pq_arrive[0][0]                          # 媛??鍮⑤━ ?꾩갑???묒뾽???쒓컙
    pq_len.append(pq_arrive.pop(0))                 # ?묒뾽湲몄씠 ?쒖쑝濡??뺣젹??諛곗뿴??異붽?

    while pq_len or pq_arrive:                      # ??諛곗뿴 以??섎굹?쇰룄 ?묒뾽???⑥븘?덉쑝硫?
        if pq_arrive and time >= pq_arrive[0][0]:   # ?꾩옱 ?쒓컙蹂대떎 ?꾩갑???쒓컙??鍮좊Ⅴ?ㅻ㈃
            pq_len.append(pq_arrive.pop(0))         # ?묒뾽湲몄씠 ?쒖쑝濡??뺣젹??諛곗뿴??異붽?
            pq_len.sort(key=operator.itemgetter(1))
        elif pq_len:                                # ?꾩쭅 ?ㅻⅨ ?묒뾽???꾩갑?섏? ?딆븯????
            arrive = pq_len[0][0]
            length = pq_len[0][1]
            answer += length                        # ?묒뾽?쒓컙??answer??異붽?
            if time < arrive:                       # ?꾩갑?쒓컙 蹂대떎 ?대Ⅸ ?쒓컙?대씪硫?
                time = arrive
            answer += time-arrive                   # ?묒뾽???섍린源뚯? 湲곕떎由??湲곗떆媛꾩쓣 ?뷀븯湲곌린
            time += length                          # ?꾩옱?쒓컙 媛깆떊
            pq_len.pop(0)
        else:
            time = pq_arrive[0][0]                  # ?꾩옱?쒓컙 媛깆떊
    return answer//len(jobs)

print(solution([[0, 3], [1, 9], [2, 6]]))       # 9