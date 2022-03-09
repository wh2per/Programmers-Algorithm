def solution(weight):
    answer = 1
    weight.sort()

    for i in weight:
        if answer < i:      # ?꾩쟻??媛믩낫???щ㈃ 留뚮뱾???녿뒗 臾닿쾶??
            break
        answer += i
    return answer