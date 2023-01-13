"""
Assignment 8
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1001-B
"""

with open('./input.txt', 'r', encoding='utf-8') as file:
    nums = list(map(int, file.read().split()))

def bubble_sort(l: list[int]) -> None:
    for times in range(1, len(l)):
        for i in range(len(l) - 1):
            if l[i+1] < l[i]:
                t = l[i]
                l[i] = l[i+1]
                l[i+1] = t

        print('第', times, '次', l)


ori = [*nums]

bubble_sort(nums)
print('原資料：', ori)
