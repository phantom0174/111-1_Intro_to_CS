"""
Assignment 4
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1001-B
"""

import math


# function from P4
def find_prime(num: int) -> bool:
    if num == 1:
        return False
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


def num_exist(num: str) -> bool:
    global datum_pos

    for (pos, datum) in enumerate(data):
        # Number_X f0 f1 f2...
        # split(' ') -> [Number_X, f0, f1...]
        # [0]        -> Number_X
        # split('_') -> [Number, X]
        # [-1]       -> X
        if num == datum.split()[0].split('_')[-1]:
            datum_pos = pos
            return True

    return False


def find_prime_num() -> int:
    global datum_pos

    prime_count = 0
    factors = list(map(int, data[datum_pos].split()[1:]))
    for factor in factors:
        if find_prime(factor):
            prime_count += 1

    return prime_count


def find_factor_num() -> int:
    global datum_pos

    return len(data[datum_pos].split()[1:])


with open('./Input.txt', 'r', encoding='utf-8') as file:
    data: list[str] = file.read().split('\n')
    if data[-1] == '':
        del data[-1]

# a global variable of the position of found data,
# will be refreshed automatically
datum_pos = -1

while True:
    target_num: str = input('Input the number to check exist or exit : ')

    if target_num == 'exit':
        break
    
    if not num_exist(target_num):
        print(f'Number_{target_num} is not exist, please input a new number or input "exit" to leave program')
        continue

    factor_count = find_factor_num()
    prime_count = find_prime_num()

    print(f'Number_{target_num} exists in the document and the number of factor is {factor_count} and the number of prime is {prime_count}')
    print('Please input the next number or input "exit" to leave')
