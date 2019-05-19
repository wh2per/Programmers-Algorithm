def solution(routes):
    answer = 0
    cam = []
    routes.sort(key=lambda e: e[0])     # 출발지점 기준으로 정렬

    for i in routes:
        cs = i[0]       # 출발지점 저장
        flag =True
        for j in cam:
            if j[0] <= cs <= j[1]:
                flag = True
            else:               # 출발 지점이 카메라 영역안에 없다면
                flag = False
                break
        if flag:
            cam.append(i)
        else:
            answer += 1
            cam.clear()
            cam.append(i)

    answer += 1
    return answer

print(solution([[-20,15], [-14,-5], [-18,-13], [-5,-3]]))