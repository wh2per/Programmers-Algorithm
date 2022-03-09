def solution(s):
    answer = ""
    split_s = s.split()
    temp = []
    for i in split_s:
        temp.append(int(i))
    temp.sort()
    answer = str(temp[0])+" "+str(temp[-1])
    return answer