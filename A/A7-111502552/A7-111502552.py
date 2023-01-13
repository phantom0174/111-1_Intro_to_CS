"""
Assignment 7
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1001-B
"""

with open('./input.txt', 'r', encoding='utf-8') as file:
    maze = [line.split() for line in file.read().split('\n')]
    if maze[-1] == []:
        del maze[-1]

def path_count(x: int, y: int):
    if x == 5 and y == 5:
        return 1

    free_path = 0
    if maze[y][x+1] == '1':
        free_path += path_count(x+1, y)
    if maze[y+1][x] == '1':
        free_path += path_count(x, y+1)
    return free_path


count = path_count(1, 1)
print(count)
