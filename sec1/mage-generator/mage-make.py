import random

def generate_maze(rows, cols):
    maze = [[1 for _ in range(cols)] for _ in range(rows)]

    def carve_passages_from(x, y):
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        random.shuffle(directions)
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < rows and 0 <= ny < cols and maze[nx][ny] == 1:
                if sum(maze[nx + dx][ny + dy] for dx, dy in directions if 0 <= nx + dx < rows and 0 <= ny + dy < cols) >= 3:
                    maze[nx][ny] = 0
                    carve_passages_from(nx, ny)

    maze[1][1] = 0
    carve_passages_from(1, 1)
    return maze

def print_maze(maze):
    for row in maze:
        print("".join(" " if cell == 0 else "#" for cell in row))

rows, cols = 21, 21
maze = generate_maze(rows, cols)
print_maze(maze)
