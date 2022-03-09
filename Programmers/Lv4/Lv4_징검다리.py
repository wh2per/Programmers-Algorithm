# ?뚮씪硫뷀듃由??쒖튂
def remove_rock(rocks, mid, n):
    prev = 0
    remove = 0

    for r in rocks:
        if r - prev > mid:
            prev = r
        else:       # mid 蹂대떎 ?묒? 媛믪씠 ?덈떎硫??쒓굅?댁빞 ????媛?닔 利앷?
            remove += 1
    if remove > n:  # ?뺥빐吏??뚮낫??留롮씠 ?쒓굅?댁빞 ?쒕떎硫?
        return True
    else:
        return False


def solution(distance, rocks, n):
    low = 0
    high = distance
    rocks.sort()
    while low <= high:
        mid = (low + high) >> 1         # mid => ?뺣떟媛??덉륫
        if remove_rock(rocks, mid, n):
            high = mid - 1              # mid 媛믪씠 ?믪? 寃?
        else:
            low = mid + 1               # mid 媛믪씠 ??? 寃?
    return low

print(solution(25, [2, 14, 11, 21, 17], 2))