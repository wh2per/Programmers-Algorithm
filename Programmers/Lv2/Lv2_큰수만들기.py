def solution(number, k):
    stack = [number[0]]
    for num in number[1:]:
        while len(stack) > 0 and stack[-1] < num and k > 0:
            k -= 1
            stack.pop()
        stack.append(num)
    if k != 0:                  # 紐⑤몢 ?묎컳? ?섎줈 ?ㅼ뼱??寃쎌슦 ?↔린
        stack = stack[:-k]      # ?ㅼ뿉?쒕???k媛??쒓굅?섍린
    return ''.join(stack)

print(solution("111111", 3))
