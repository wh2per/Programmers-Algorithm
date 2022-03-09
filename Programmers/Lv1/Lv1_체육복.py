def solution(n, lost, reserve):
    answer = 0
    for i in range(1, n + 1):
        if i not in lost:  # ???껋뼱踰꾨┛ ?숈깮
            answer += 1
        else:
            if i in reserve:  # ?껋뼱踰꾨졇吏留??щ텇???덈뒗 ?숈깮
                answer += 1
                reserve.remove(i)
                lost.remove(i)

    for i in lost:  # ?껋뼱踰꾨━怨??щ텇???놁뼱??鍮뚮젮???섎뒗 ?숈깮
        if i - 1 in reserve:
            answer += 1
            reserve.remove(i - 1)

        elif i + 1 in reserve:
            answer += 1
            reserve.remove(i + 1)
    return answer

print(solution(5,[2,4],[3]))