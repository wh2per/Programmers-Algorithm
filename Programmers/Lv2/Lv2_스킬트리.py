def solution(skill, skill_trees):
    answer = 0
    check = []
    temp = ""
    for i in skill:
        check.append(i)

    for i in skill_trees:
        index = 0
        flag = False
        for j in i:
            if j in check:
                if skill[index] == j:
                    index += 1
                else:
                    flag = True
                    break
        if flag == False:
            answer += 1
    return answer