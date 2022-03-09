import math
def solution(n):
    a = int(math.sqrt(n))
    if a * a == n :
        return (a+1)**2
    else:
        return -1