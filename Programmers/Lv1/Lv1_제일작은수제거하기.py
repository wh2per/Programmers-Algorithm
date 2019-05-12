def solution(arr):
    if len(arr)==1:
        return [-1]
    else:
        answer = []
        temp = sorted(arr)
        a = temp[0]
        arr.remove(a)
        return arr
