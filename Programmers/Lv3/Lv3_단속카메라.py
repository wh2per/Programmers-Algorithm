def solution(routes):
    answer = 0
    cam = []
    routes.sort(key=lambda e: e[0])     # 異쒕컻吏??湲곗??쇰줈 ?뺣젹

    for i in routes:
        cs = i[0]       # 異쒕컻吏?????
        flag =True
        for j in cam:
            if j[0] <= cs <= j[1]:
                flag = True
            else:               # 異쒕컻 吏?먯씠 移대찓???곸뿭?덉뿉 ?녿떎硫?
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