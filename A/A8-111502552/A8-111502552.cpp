/*
Assignment 8
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1001-B
*/

# include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a = 0, b = 0;
    cin >> a >> b;

    int lcm = a * b / gcd(a, b);
    cout << lcm << endl;
    return 0;
}
