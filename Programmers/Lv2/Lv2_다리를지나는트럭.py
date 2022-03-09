def solution(bridge_length, weight, truck_weights):
    q = []
    time = 0
    total = 0

    while len(truck_weights) > 0 or len(q) > 0:
        time += 1
        if len(q) > 0 and time - q[0][1] == bridge_length:
            temp = q.pop(0)[0]
            total -= temp

        if len(truck_weights) > 0 and total + truck_weights[0] <= weight:
            next = truck_weights.pop(0)
            q.append((next, time))
            total += next

    return time