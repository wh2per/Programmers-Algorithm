def solution(array, commands):
    answer = []
    for i in commands:
        start, end, order = i
        answer.append(sorted(array[start-1:end])[order-1])
    return answer

array = [1, 5, 2, 6, 3, 7, 4]
commands = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]
print(solution(array,commands))