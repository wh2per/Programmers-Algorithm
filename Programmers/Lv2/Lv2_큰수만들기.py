def solution(number, k):
    stack = [number[0]]
    for num in number[1:]:
        while len(stack) > 0 and stack[-1] < num and k > 0:
            k -= 1
            stack.pop()
        stack.append(num)
    if k != 0:                  # 모두 똑같은 수로 들어온 경우 잡기
        stack = stack[:-k]      # 뒤에서부터 k개 제거하기
    return ''.join(stack)

print(solution("111111", 3))
