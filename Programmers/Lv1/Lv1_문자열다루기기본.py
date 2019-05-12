def solution(s):
    if len(s)==4 or len(s)==6:
        if s.isdigit():
            return True
        else:
            return False
    else:
        return False
