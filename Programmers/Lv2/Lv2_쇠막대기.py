def solution(arrangement):
    answer = 0
    stack= []
    for i in range(len(arrangement)):
        if arrangement[i]=='(':     # 막대기의 시작
            stack.append(i)
        elif arrangement[i]==')':   # 막대기 종료 or 레이저
            if stack[-1]+1==i:      # 레이저일 경우
                stack.pop()
                answer += len(stack)
            else:                   # 막대기의 종료일 경우
                stack.pop()
                answer += 1
    return answer

print(solution(	"()(((()())(())()))(())"))