# 移댄깉???
# x = 2nCn - 2nCn+1
import math
def solution(n):
    return math.factorial(2*n) // (math.factorial(n+1) * math.factorial(n))

print(solution(4))