/*
Assignment 12
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1001-B
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> map;

// x and y is the dimension of the map
int x, y, biggest_land = 0;

int find_land(int pos_x, int pos_y) {
    map[pos_x][pos_y] = 0;  // the block has been stepped on

    int block_count = 1;
    if (pos_x - 1 >= 0 && map[pos_x - 1][pos_y]) {  // up
        block_count += find_land(pos_x - 1, pos_y);
    }
    if (pos_x + 1 < x && map[pos_x + 1][pos_y]) {  // down
        block_count += find_land(pos_x + 1, pos_y);
    }
    if (pos_y + 1 < y && map[pos_x][pos_y + 1]) {  // right
        block_count += find_land(pos_x, pos_y + 1);
    }
    if (pos_y - 1 >= 0 && map[pos_x][pos_y - 1]) {  // left
        block_count += find_land(pos_x, pos_y - 1);
    }

    return block_count;
}

void traverse_map() {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (!map[i][j]) continue;

            int land_area = find_land(i, j);
            if (land_area > biggest_land) biggest_land = land_area;
        }
    }
}

void input_map() {
    cin >> x >> y;
    for (int i = 0; i < x; i++) {
        vector<bool> line;
        bool value;
        for (int j = 0; j < y; j++) {
            cin >> value;
            line.push_back(value);
        }
        map.push_back(line);
    }
}

int main() {
    input_map();
    traverse_map();

    cout << biggest_land << endl;
}
