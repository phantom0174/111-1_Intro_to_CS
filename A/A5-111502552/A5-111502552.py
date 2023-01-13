"""
Assignment 5
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1001-B
"""

# chinese, english, math, science

NAME_TO_INDEX = {
    'chinese': 1,
    'english': 2,
    'math': 3,
    'science': 4 
}

SCORE_STANDARDS = [12, 12, 8, 12]

def split_info(info: list[str]):
    # info.length % 5 must be 0 (5 data for each student)
    data_count = int(len(info) / 5)

    return_list = []
    for segment_num in range(data_count):
        return_list.append(info[5 * segment_num : 5 * (segment_num + 1) + 1])
    return return_list


def grading_system(student_list: list[str]):
    for (i, standard) in enumerate(SCORE_STANDARDS):
        if int(student_list[i + 1]) < standard:
            # return false if any failed
            return f"Sorry, {student_list[0]} can't enter NCU CSIE."

    return f"Hello {student_list[0]}, welcome to NCU CSIE!"


def find_grade(s_list: list[list[str]], name: str, subject: str):
    subject_index = NAME_TO_INDEX.get(subject)

    # subject does not exists
    if not subject_index:
        return 'Error'

    for student_data in s_list:
        if student_data[0] == name:
            return student_data[NAME_TO_INDEX[subject]]
    
    return 'Error'


def main():
    output = open('./output.txt', 'w+', encoding='utf-8')

    with open('./score.txt', 'r', encoding='utf-8') as file:
        info = [word.strip('\n') for word in file.read().split()]

    splitted_info = split_info(info)

    # determine whether the student can enter or not
    for student_info in splitted_info:
        grading_result = grading_system(student_info)
        print(grading_result, file=output)

    with open('./cmd.txt', 'r', encoding='utf-8') as file:
        cmds = file.read().split('\n')

    if cmds[-1] == '':
        del cmds[-1]

    # process every command
    for cmd in cmds:
        name = cmd.split(' ')[0]
        subject = cmd.split(' ')[1]
        find_result = find_grade(splitted_info, name, subject)
        print(find_result, file=output)

    output.close()

main()
