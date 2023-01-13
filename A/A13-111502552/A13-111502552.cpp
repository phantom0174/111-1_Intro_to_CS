/*
Assignment 13
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1001-B
*/

#include <iostream>

using namespace std;

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int *mergearray(int *arr1, int *arr2, int length, int (*ptr)(int, int)) {
    int *result = new int[length];
    for (int i = 0; i < length; i++) {
        result[i] = (*ptr)(arr1[i], arr2[i]);
    }
    return result;
}


int main() {
    int ARR_SIZE;
    cin >> ARR_SIZE;

    int *A = new int[ARR_SIZE], *B = new int[ARR_SIZE];

    for (int i = 0; i < ARR_SIZE; i++) cin >> A[i];
    for (int i = 0; i < ARR_SIZE; i++) cin >> B[i];

    string op;
    cin >> op;

    int (*func)(int, int);
    if (op == "add") {
        func = add;
    } else if (op == "sub") {
        func = sub;
    } else if (op == "mul") {
        func = mul;
    }

    int *op_result = mergearray(A, B, ARR_SIZE, *func);
    for (int i = 0; i < ARR_SIZE; i++) {
        cout << op_result[i] << " ";
    }
    cout << endl;

    delete[] op_result;
    delete[] A;
    delete[] B;
}
