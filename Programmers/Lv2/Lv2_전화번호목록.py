def solution(phone_book):
    for i in range(0, len(phone_book)-1):
        for j in range(i+1, len(phone_book)):
            if phone_book[i].startswith(phone_book[j]):
                return False
            if phone_book[j].startswith(phone_book[i]):
                return False
    return True