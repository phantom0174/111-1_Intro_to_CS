/*
Assignment 11
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1001-B
*/

#include <iostream>
#include <map>

using namespace std;

map<string, map<int, short>> get_input(map<string, map<int, short>> doll_map) {
    int doll_count;
    cin >> doll_count;

    string doll_type;
    int doll_size;
    for (int i = 0; i < doll_count; i++) {
        cin >> doll_size >> doll_type;
        if (!doll_map[doll_type][doll_size]) {
            doll_map[doll_type][doll_size] = 1;
        } else {
            doll_map[doll_type][doll_size]++;
        }
    }
    return doll_map;
}

short count_max_pieces(map<int, short>& pieces_count) {
    short max = 0;
    for (auto [key, value] : pieces_count) {
        if (value > max) max = value;
    }
    return max;
}

void calculate_doll(map<string, map<int, short>>& doll_map) {
    int visible_doll_count = 0;
    for (auto [key, value] : doll_map) {
        visible_doll_count += count_max_pieces(value);
    }
    cout << visible_doll_count << endl;
}

int main() {
    map<string, map<int, short>> dolls;

    dolls = get_input(dolls);    
    calculate_doll(dolls);
}
