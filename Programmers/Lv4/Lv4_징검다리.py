# 파라메트릭 서치
def remove_rock(rocks, mid, n):
    prev = 0
    remove = 0

    for r in rocks:
        if r - prev > mid:
            prev = r
        else:       # mid 보다 작은 값이 있다면 제거해야 할 돌 갯수 증가
            remove += 1
    if remove > n:  # 정해진 돌보다 많이 제거해야 한다면
        return True
    else:
        return False


def solution(distance, rocks, n):
    low = 0
    high = distance
    rocks.sort()
    while low <= high:
        mid = (low + high) >> 1         # mid => 정답값 예측
        if remove_rock(rocks, mid, n):
            high = mid - 1              # mid 값이 높은 것
        else:
            low = mid + 1               # mid 값이 낮은 것
    return low

print(solution(25, [2, 14, 11, 21, 17], 2))