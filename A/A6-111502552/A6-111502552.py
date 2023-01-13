"""
Assignment 6
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1001-B
"""

import math

def to_deci(base: int, num: str):
    if not num.isnumeric():
        return False
    
    num = num[::-1]

    value = 0
    for i, c in enumerate(num):
        if (int(c) >= base):
            return False

        value += int(c) * pow(base, i)
    return value


while True:
    num = str(input('NUM(BIN) : '))

    if num == '-1':
        break

    # base 2 to 10
    deci = to_deci(2, num)

    if not deci:
        print('Not Binary Number!')
        continue

    print(f'NUM(DEC) : {deci}')


    # base 2 to 8
    segment_count = math.ceil(len(num) / 3)
    insert_0_count = 3 * segment_count - len(num)

    num = '0' * insert_0_count + num

    oct = ''
    for i in range(segment_count):
        oct += str(to_deci(2, num[(i * 3):((i + 1) * 3)]))
    oct = oct.lstrip('0')

    print(f'NUM(OCT) : {oct}')
