/*
Assignment 10
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1001-B
*/

#include <iostream>
#include <vector>

using namespace std;

// ========== Global Variables ==========

vector<string> g_token_list;  // Global token list

// identifier, num, special_symbol, unknown
int TYPES_COUNT[4] = {
    0, 0, 0, 0
};

const vector<char> SPECIAL_SYMBOLS = {
    '+', '-', '*', '/', '>', '<', '=', '%', '&', '|',
    '^', '\"', '\'', '.', ',', '(', ')', '[', ']', '{',
    '}', '!', ':', ';'
};

const vector<string> SPECIAL_DOUBLE_SYMBOLS = {
    "++", "--", "+=", "<=", ">=", "==", "!=", "&&", "||"
};

// ========== Functions ==========

bool is_number(char c) {
    // given a character, return true if it is a number
    // using ascii code to determine whether c is a number

    if ((int)c < 48 || (int)c > 57) return false;
    return true;
}

bool is_special_symbol(char c) {
    // given a character, return true if it is a special symbol or not

    for (char symbol : SPECIAL_SYMBOLS) {
        if (c == symbol) return true;
    }
    return false;
}

bool is_double_special_symbol(string s) {
    for (string double_symbol : SPECIAL_DOUBLE_SYMBOLS) {
        if (s == double_symbol) return true;
    }
    return false;
}

bool is_alphabet(char c) {
    // using ascii code to determine whether c is an alphabet
    if ((int)c < 65 || ((int)c > 90 && (int)c < 97) || (int)c > 122) return false;
    return true;
}

bool is_unknown_token(char c) {
    // none of the above
    return !(is_number(c) || is_special_symbol(c) || is_alphabet(c));
}

// <core parser>: parsing & type-deciding
vector<string> parser(string line) {
    vector<string> id;

    while (line.length() > 0) {
        int breakpoint = -1;
        if (is_alphabet(line[0]) || line[0] == '_') {  // pattern of identifier
            for (int i = 0; i < line.length(); i++) {
                if (line[i] != '_' && (is_special_symbol(line[i]) || is_unknown_token(line[i]))) {
                    breakpoint = i;
                    break;
                }
            }
            TYPES_COUNT[0]++;
        } else if (is_special_symbol(line[0])) {  // pattern of special-symbol
            if (line.length() > 1 && is_double_special_symbol(line.substr(0, 2))) {
                breakpoint = 2;
            } else {
                breakpoint = 1;
            }
            TYPES_COUNT[2]++;
        } else if (is_number(line[0])) {  // pattern of number
            for (int i = 0; i < line.length(); i++) {
                if (!is_number(line[i])) {
                    breakpoint = i;
                    break;
                }
            }
            TYPES_COUNT[1]++;
        } else if (is_unknown_token(line[0])) {  // pattern of unknown-token
            breakpoint = 1;
            TYPES_COUNT[3]++;
        }

        if (breakpoint == -1) breakpoint = line.length();
        id.push_back(line.substr(0, breakpoint));
        line = line.substr(breakpoint);
    }
    return id;
}

void get_user_input() {
    // Get user input until END_OF_FILE appears, and store the tokens into g_token_list.

    string s;
    while (cin >> s) {
        if (s == "END_OF_FILE") return;

        vector<string> parsed_tokens = parser(s);
        for (string token : parsed_tokens) g_token_list.push_back(token);
    }
}

void print_token_sum(int sum) {
    cout << "Total number of tokens: " << sum << endl;
}

void print_token(string token) {
    cout << "[" << token << "]" << endl;
}

void print_types_info() {
    cout << "Identifier: " << TYPES_COUNT[0] << ", "
         << "Number: " << TYPES_COUNT[1] << ", "
         << "Special Symbol: " << TYPES_COUNT[2] << endl;
}

void print_invalid_command() {
    cout << "Invalid command." << endl;
}

void execute_command(int cmd) {
    // Given a command:
    // if command == 1, print token sum
    // if command == 2, print all tokens
    // if command == 3, token sum in each cases

    if (cmd == 1) {
        print_token_sum(g_token_list.size());
    } else if (cmd == 2) {
        for (string token : g_token_list) print_token(token);
    } else if (cmd == 3) {
        print_types_info();
    } else {
        print_invalid_command();
    }
}

// ========== Main Function ==========

int main() {
    // Get User Input form the input stream, and execute the command until command == 0.

    get_user_input();

    int cmd;
    while (cin >> cmd) {
        if (cmd == 0) break;
        execute_command(cmd);
    }
}
