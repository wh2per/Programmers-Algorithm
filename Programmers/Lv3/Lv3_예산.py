def solution(budgets, M):
    right = max(budgets)
    left = 0
    
    while left <= right:
        total = 0
        mid = (left+right)>>1
        for i in budgets:
            if i < mid:
                total += i
            else:
                total += mid
        if total > M:
            right = mid-1
        else:
            left = mid + 1
    return right
print(solution([120, 110, 140, 150], 485))      # 127