def solution(n, times):
    left = 0
    right = n * max(times)

    while left < right:
        mid = (left+right)>>1       
        count = 0
        for i in range(len(times)):
            count += mid//times[i]
        if count >= n:
            right = mid
        else:
            left = mid+1

    return left

print(solution(	6, [7, 10]))        # 28