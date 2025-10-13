
def solution(A):
    events = []
    # 先に軸との交差点を求める
    for i, a in enumerate(A):
        events += [(i-a, +1), (i+a, -1)]
    events.sort(key=lambda x: (x[0], -x[1]))
    intersections, active_circles = 0, 0
    for _, circle_count_delta in events:
        print((circle_count_delta > 0))
        intersections += active_circles * (circle_count_delta > 0)
        active_circles += circle_count_delta
        if intersections > 10E6:
            return -1
    return intersections

solution([3,5,1,6,1])