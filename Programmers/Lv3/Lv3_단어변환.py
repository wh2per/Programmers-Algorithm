answer = 999999999
check = []

def DFS(cur, target, cnt, words):
    global answer
    global check

    if cur == target:
        if answer > cnt:
            answer = cnt
        return

    for i in range(len(words)):
        if check[i]:       # 이미 사용한 단어라면 패스
            continue
        diff = 0
        for j in range(len(cur)):
            if cur[j] != words[i][j]:
                diff += 1
        if diff != 1:       # 다른 글자가 1개가 아니면 패스
            continue

        check[i] = True
        DFS(words[i], target, cnt + 1, words)
        check[i] = False

def solution(begin, target, words):
    global answer
    global check

    check = [False]*len(words)

    for i in range(len(words)):
        diff = 0
        for j in range(len(begin)):
            if begin[j] != words[i][j]:
                diff += 1
        if diff != 1:
            continue
        check[i] = True
        DFS(words[i], target, 1, words)
        check[i] = False

    if answer == 999999999:
        return 0
    else:
        return answer
print(solution("hit", "cog", ["hot", "dot", "dog", "lot", "log"]))      # 0