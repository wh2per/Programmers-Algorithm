# DP
# 留??룹옄由щ????쒓??먯뵫 ?섎젮媛硫??뺤씤
def solution(strs, t):
    answer = 0
    size = len(t)
    s = []
    d = [99999999 for x in range(size+1)]

    for i in strs:      # ?⑥뼱 議곌컖???쎌엯
        s.append(i)

    d[size] = 0
    for i in range(size-1, -1, -1):
        temp = ""
        for j in range(i, size):
            temp += t[j]
            if s.count(temp) != 0:           # ?덉쑝硫?
                if d[j+1] != 99999999:
                    d[i] = min(d[i], d[j+1] + 1)
            if j > i + 5:
                break
    if d[0] != 99999999:
        answer = d[0]
    else:
        answer = -1
    return answer
print(solution(	["ab", "na", "n", "a", "bn"], "nabnabn"))