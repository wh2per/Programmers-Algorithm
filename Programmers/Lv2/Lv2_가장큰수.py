import functools

def comparator(a,b):
    t1 = a+b
    t2 = b+a
    return int(t1) - int(t2) #  t1이 크다면 1, t2가 크다면 -1   같으면 0

def solution(numbers):
    n = [str(x) for x in numbers]
    n = sorted(n, key=functools.cmp_to_key(comparator),reverse=True)
    return str(int(''.join(n)))

print(solution([3, 30, 34, 5, 9]))