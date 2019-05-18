def solution(s):
    answer = True
    stack = []
    for i in s:
        if i == ')':
            if len(stack) == 0:
                return False
            else:
                if stack[-1] == '(':
                    stack.pop()
                else:
                    return False
        else:
            stack.append(i)

    if len(stack) > 0:
        return False
    else:
        return True