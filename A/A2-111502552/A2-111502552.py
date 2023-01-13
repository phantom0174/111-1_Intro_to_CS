"""
Assignment 2
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1001-B
"""

ERROR_TEMPLATE = 'try again or type "exit" to leave.'
SPECIAL_CHARS = """~!@#$%^&*()_+|`-=\{}[]:";'<>?,./ """


while True:
    pw = input('Please enter your password: ')
    if pw == 'exit':
        break

    pw_cert = input('Please enter your password again: ')

    if pw != pw_cert:
        print(f'Password settings are not consistent, {ERROR_TEMPLATE}')
        continue

    if len(pw) < 6 or len(pw) > 10:
        print(f'Password should contain 6 to 10 characters, {ERROR_TEMPLATE}')
        continue

    has_upper = False
    has_lower = False
    has_num = False
    has_spec = False
    for char in pw:
        if char.isupper():
            has_upper = True
        elif char.islower():
            has_lower = True
        elif char.isdecimal():
            has_num = True
        elif char in SPECIAL_CHARS:
            has_spec = True

    if not has_upper:
        print(f'Password should contain at least one upper-case alphabetical character, {ERROR_TEMPLATE}')
    elif not has_lower:
        print(f'Password should contain at least one lower-case alphabetical character, {ERROR_TEMPLATE}')
    elif not has_num:
        print(f'Password should contain at least one number, {ERROR_TEMPLATE}')
    elif not has_spec:
        print(f'Password should contain at least one special character, {ERROR_TEMPLATE}')
    elif pw == pw[::-1]:
        print(f'Symmetric password is not allowed, {ERROR_TEMPLATE}')
    else:
        print('Password is valid.')
        break
