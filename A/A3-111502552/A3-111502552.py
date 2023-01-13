"""
Assignment 3
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1001-B
"""

import math


def isPrime(num):
    if num == 2 or num == 3:
        return True
    
    # even numbers are not primes
    if num % 2 == 0:
        return False

    # sieve of Eratosthenes
    for i in range(3, math.floor(math.sqrt(num)) + 1, 2):
        if num % i == 0:
            return False

    return True


def CreatePyramid():
    layer: int = 0

    # read total layer from file
    with open('./input.txt', 'r', encoding='utf-8') as file:
        layer = int(file.read())

    
    pyramid = [] # string list of each layer

    cur_num = 1 # the initial-number for each layer
    
    for l in range(1, layer + 1):
        white_count = layer - l
        num_count = 2 * l - 1

        layer_text = ' ' * white_count # a temp string to be pushed into var: pyramid

        # converting numbers of each layer into 'Y'/'N'
        for layer_num in range(cur_num, cur_num + num_count):
            if layer_num == 1:
                layer_text += '1'
            elif isPrime(layer_num):
                layer_text += 'Y'
            else:
                layer_text += 'N'

        pyramid.append(layer_text)
        cur_num += num_count 

    with open('./output.txt', 'w+', encoding='utf-8') as file:
        file.write('\n'.join(pyramid))


CreatePyramid()
