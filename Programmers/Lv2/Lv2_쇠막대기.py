def solution(arrangement):
    answer = 0
    stack= []
    for i in range(len(arrangement)):
        if arrangement[i]=='(':     # 留됰?湲곗쓽 ?쒖옉
            stack.append(i)
        elif arrangement[i]==')':   # 留됰?湲?醫낅즺 or ?덉씠?
            if stack[-1]+1==i:      # ?덉씠???寃쎌슦
                stack.pop()
                answer += len(stack)
            else:                   # 留됰?湲곗쓽 醫낅즺??寃쎌슦
                stack.pop()
                answer += 1
    return answer

print(solution(	"()(((()())(())()))(())"))