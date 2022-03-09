def solution(n, words):
    answer = []
    prev = words[0][0]
    s = list()
    for i in range(0, len(words)):
        if words[i][0] != prev:
            answer.append((i % n) + 1)
            answer.append((i // n) + 1)
            break
        else:
            if words[i] in s:
                answer.append((i % n) + 1)
                answer.append((i // n) + 1)
                break
            else:
                s.append(words[i])
                prev = words[i][-1]
    if len(answer)==0:
        return [0,0]
    else:
        return answer