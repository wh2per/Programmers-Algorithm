def solution(s):
    s = s.lower()
    answer = []
    if len(s)==1:
        return 1
    else:
        for i in range(len(s)):
            for j in range(0, i):
                temp = s[j:i + 1]

                if temp == temp[::-1]:      # 뒤집었을 때와 같은지
                    answer.append(temp)
        if answer:
            return len(max(answer, key=len))
        else:
            return 1

print(solution("asdf"))