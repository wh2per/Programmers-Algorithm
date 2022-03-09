check = []
tmp = "a"

def DFS(tickets, end, count, path):
    global check
    global tmp

    if count >= len(tickets):
        if tmp > path:
            tmp = path
        return

    for i in range(len(tickets)):       # ?ъ슜???곗폆 李얘린
        if check[i] == False and tickets[i][0] == end:
            check[i] = True
            DFS(tickets, tickets[i][1], count + 1, path+tickets[i][1])
            check[i] = False


def solution(tickets):
    global check
    global tmp

    check = [False] * len(tickets)
    DFS(tickets, "ICN", 0, "ICN")
    answer = []

    for i in range(0,len(tmp),3):
        answer.append(tmp[i:i+3])

    return answer

print(solution(	[["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL", "SFO"]]))
# 	["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]