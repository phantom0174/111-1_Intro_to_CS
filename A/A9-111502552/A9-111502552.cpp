/*
Assignment 9
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1001-B
*/

#include <iostream>

using namespace std;

int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) return 1;
    return 0;
}

// Gauss's algorithm
int which_date(int year, int month, int day) {
    // month offset
    int m = month - 2;
    if (m == -1 || m == 0) m += 12;

    // year offset
    if (month == 1 || month == 2) year -= 1;

    int c = year / 100;
    int y = year % 100;

    return (day + (int)(2.6 * m - 0.2) + 5 * (y % 4) + 3 * y + 5 * (c % 4)) % 7;
}

void display_calendar(int year, int month, int day) {
    int target_date = which_date(year, month, day);

    // the date of start of the month
    int first = which_date(year, month, 1);

    // the day of the end of the month
    int last_day = 0;
    if (month <= 7) {
        if (month == 2) {
            last_day = 28 + is_leap_year(year);
        } else {
            last_day = 30 + (month % 2);
        }
    } else {
        last_day = 31 - (month % 2);
    }

    for (int i = 0; i < 7; i++) cout << "    " << i;
    cout << endl
         << "=====================================" << endl;

    // main
    for (int pre = 0; pre < first; pre++) cout << "     ";
    for (
        int week = first, curr_date = 1;
        curr_date <= last_day;
        week = (week + 1) % 7, curr_date++) {
        if (curr_date == day) {
            if (day >= 10)
                cout << "  *" << day;
            else
                cout << "   *" << day;
        } else {
            if (curr_date >= 10)
                cout << "   " << curr_date;
            else
                cout << "    " << curr_date;
        }
        if (week == 6 && curr_date != last_day) cout << endl;
    }
    // ---

    cout << endl
         << "=====================================" << endl;
}

void display_text(int year, int month, int day) {
    int target_date = which_date(year, month, day);
    switch (target_date) {
        case 0:
            cout << "Sunday" << endl;
            break;
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
    }
    cout << endl;
}

int main() {
    int year, month, day;
    cin >> year >> month >> day;
    display_text(year, month, day);

    display_calendar(year, month, day);
}
