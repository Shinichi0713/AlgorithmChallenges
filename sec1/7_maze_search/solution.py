
import os

def solution(maze):
    pass


def read_maze(file_path):
    with open(file_path) as f:
        lines = f.readlines()
        maze = [[cell for cell in line.strip()] for line in lines]
    return maze

if __name__ == '__main__':
    dir_current = os.path.dirname(__file__)
    maze = read_maze(f'{dir_current}/maze.txt')
    solution(maze)
