import functools

def comparator(a,b):
    t1 = a+b
    t2 = b+a
    return int(t1) - int(t2) #  t1???щ떎硫?1, t2媛 ?щ떎硫?-1   媛숈쑝硫?0

def solution(numbers):
    n = [str(x) for x in numbers]
    n = sorted(n, key=functools.cmp_to_key(comparator),reverse=True)
    return str(int(''.join(n)))

print(solution([3, 30, 34, 5, 9]))