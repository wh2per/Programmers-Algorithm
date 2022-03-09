def solution(name):
    tname = []
    for i in name:
        tname.append(i)
    answer = 0
    solv = 0
    for i in name:
        if i != 'A':
            solv += 1
    end = len(name)/2

    index = 0
    while solv != 0:
        if tname[index] != 'A':          # ?꾩옱 ?먮━???섏젙???꾩슂?섎떎硫?
            solv -= 1
            temp = ord(tname[index]) - ord('A')
            if temp > 13:
                answer += 26-temp
            else:
                answer += temp
            tname[index] = 'A'
        if solv == 0:
            break
        # ?ㅻⅨ履?寃??
        rs = index
        rt = 1
        while rt <= end:
            rs += 1
            if rs > len(name)-1:
                rs = 0
            if tname[rs] != 'A':
                break
            else:
                rt += 1

        # ?쇱そ 寃??
        ls = index
        lt = 1
        while lt <= end:
            ls -= 1
            if ls < 0:
                ls = len(name)-1
            if tname[ls] != 'A':
                break
            else:
                lt += 1

        if rt > lt:
            answer += lt
            index = ls
        else:
            answer += rt
            index = rs
    return answer

print(solution("AZAAAZ"))