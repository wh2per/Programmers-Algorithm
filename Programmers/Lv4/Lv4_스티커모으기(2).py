def solution(sticker):
    answer = 0
    d = [0 for x in range(len(sticker))]

    if len(sticker) == 1:
        return sticker[0]
    elif len(sticker) == 2:
        return max(sticker[0], sticker[1])
    else:
        # 첫번째 스티커 사용
        d[0] = sticker[0]
        d[1] = sticker[0]
        for i in range(2, len(sticker)-1):
            d[i] = max(d[i-2] + sticker[i], d[i-1])
        answer = d[len(sticker) - 2]

        # 첫번째 스티커 사용 x
        d[0] = 0
        d[1] = sticker[1]
        for i in range(2,len(sticker)):
            d[i] = max(d[i-2] + sticker[i], d[i-1])
        answer = max(answer, d[len(sticker) - 1])
    return answer