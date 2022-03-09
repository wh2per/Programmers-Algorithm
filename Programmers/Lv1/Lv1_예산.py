def solution(d, budget):
    answer = 0
    d.sort()
    ans = 0
    for a in d:
        ans += a
        answer += 1
        if(ans>budget):
            answer -= 1
            break;
    return answer

print(solution([1,3,2,5,4],9))