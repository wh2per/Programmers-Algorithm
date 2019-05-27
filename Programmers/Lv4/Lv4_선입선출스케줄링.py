def solution(n, cores):
    low = 0
    high = 100000
    mid = (low + high) >> 1

    while low < high:
        count = 0
        temp = 0

        for a in cores:
            count += (mid // a) + 1
            if mid % a == 0:
                temp += 1
                count -= 1
        if count >= n:
            high = mid
        elif count + temp < n:
            low = mid + 1
        else:
            break
        mid = (high + low) >> 1

    for i in range(len(cores)):
        if mid % cores[i] == 0:
            count += 1
        if count == n:
            return i + 1
