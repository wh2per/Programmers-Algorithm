def solution(nums):
    s = set()
    for i in nums:
        s.add(i)

    if len(nums) // 2 < len(s):
        return len(nums) // 2
    else:
        return len(s)