def solution(people, limit):
    answer = 0
    people.sort(reverse=True)       # ?대┝李⑥닚 ?뺣젹
    a = 0
    b = len(people)-1
    while a<=b:
        if people[a] + people[b] <= limit:
            b -= 1
        answer += 1
        a += 1
    return answer

print(solution([70, 80, 50], 100))