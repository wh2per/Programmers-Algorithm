def solution(progresses, speeds):
    answer = []
    temp = []
    for i, j in zip(progresses, speeds):
        diff = 100 - i
        count = 0
        if diff%j==0:
            count = diff//j
        else:
            count = (diff//j)+1
        temp.append(count)
    temp.reverse()
    while len(temp)>0:
        t1 = temp[-1]       # 理쒖긽??
        t2 = 1              # 1媛쒕줈 珥덇린??
        temp.pop()          # ?쒓굅
        while len(temp)!=0 and temp[-1] <= t1:      # 理쒖긽?꾧? ?섎옉 媛숆굅???묒쑝硫?異붽?
            temp.pop()
            t2 += 1
        answer.append(t2)
    return answer

print(solution(	[93, 30, 55], [1, 30, 5]))