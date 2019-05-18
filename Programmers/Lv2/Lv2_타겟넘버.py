answer = 0

def oper(i,num,sum):
    if i==0:
        sum += num
    elif i==1:
        sum -= num
    return sum

def go(numbers, target, index, result):
    global answer
    if result == target and index == len(numbers):
        answer += 1
        return
    if index > len(numbers)-1:
        return
    go(numbers,target, index+1, oper(0,numbers[index], result))
    go(numbers,target, index+1, oper(1,numbers[index], result))

def solution(numbers, target):
    go(numbers,target,0,0)
    return answer

print(solution([1, 1, 1, 1, 1], 3))