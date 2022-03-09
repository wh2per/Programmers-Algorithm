import math
def get_num(target):        # ?먯떊???쒖쇅??理쒕? ?쎌닔瑜?諛섑솚
    end = int(math.sqrt(target))
    if end*end<target:
        end += 1
    temp = 2

    for i in range(2,end+1):
        temp = i
        if target%i==0:
            break

    if temp * temp > target:
        return 1;
    return target//temp


def solution(begin, end):
    answer = []
    start_block = 1
    end_block = end>>1

    if begin==1:
        answer.append(0)
        begin += 1

    for i in range(begin,end+1):
        answer.append(get_num(i))
    return answer

print(solution(1, 10))