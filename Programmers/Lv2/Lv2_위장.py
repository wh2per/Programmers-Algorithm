def solution(clothes):
    m = {}
    for i in clothes:
        if i[1] in m:
            m[i[1]] += 1
        else:
            m[i[1]] = 1
    answer = 1
    for i in m.values():
        answer *= i+1
    return answer-1

print(solution(	[["crow_mask", "face"], ["blue_sunglasses", "face"], ["smoky_makeup", "face"]]))