def solution(baseball):
    answer = 0
    for i in range(123,988):
        s = str(i)
        if s.count(s[0])>1 or s.count(s[1])>1 or s.count(s[2])>1 or s.count('0')>0:
            continue
        check = False
        for j in baseball:
            strike = 0
            ball = 0
            target = str(j[0])
            for k in range(3):
                if s[k]==target[k]:
                    strike += 1
                elif target.count(s[k])==1:
                    ball += 1
            if strike != j[1] or ball != j[2]:
                check = True
                break
        if check==False:
            answer += 1
    return answer