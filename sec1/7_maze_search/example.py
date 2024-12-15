from collections import deque

def bfs(maze, start, goal):
    rows, cols = len(maze), len(maze[0])
    queue = deque([start])
    visited = set()
    visited.add(start)
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    while queue:
        x, y = queue.popleft()
        if (x, y) == goal:
            return True  # ゴールに到達

        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < rows and 0 <= ny < cols and maze[nx][ny] != '*' and (nx, ny) not in visited:
                queue.append((nx, ny))
                visited.add((nx, ny))

    return False  # ゴールに到達できない

# 迷路の定義
maze = [
    ['S', ' ', '*', '*', '*', '*', '*', '*', '*', '*'],
    [' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'],
    ['*', '*', '*', ' ', '*', ' ', '*', '*', ' ', '*'],
    ['*', ' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', '*'],
    ['*', ' ', '*', '*', '*', ' ', '*', '*', '*', '*'],
    ['*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'],
    ['*', '*', '*', ' ', '*', '*', '*', '*', ' ', '*'],
    ['*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*'],
    ['*', ' ', '*', '*', '*', '*', ' ', '*', ' ', '*'],
    ['*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G']
]

start = (0, 0)
goal = (9, 9)

if bfs(maze, start, goal):
    print("ゴールに到達しました！")
else:
    print("ゴールに到達できませんでした。")
