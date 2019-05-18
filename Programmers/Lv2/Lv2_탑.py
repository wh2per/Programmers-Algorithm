def solution(heights):
    answer = []
    for i in range(len(heights)-1, 0, -1):
        flag = True
        for j in range(i-1, -1, -1):
            if heights[j]>heights[i]:
                answer.append(j+1)
                flag = False
                break;
        if flag:
            answer.append(0)
    answer.append(0)
    answer.reverse()
    return answer

print(solution(	[6, 9, 5, 7, 4]))