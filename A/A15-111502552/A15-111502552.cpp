/*
Assignment 15
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1001-B
*/

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

ifstream input_file("./input.txt", ios::in);
ofstream output_file("./output.txt", ios::out);

// weight encoding
vector<char> SUITS_WEIGHT_ENCODE = { 'C', 'D', 'S', 'H' };
vector<char> FIGURE_WEIGHT_ENCODE = {
    '-', '-', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'
};
vector<char> DIRECTION_ENCODE = { 'S', 'W', 'N', 'E' };
//

int encode_char(char c, string type) {
    vector<char> encode_vector;
    if (type == "suit") {
        encode_vector = SUITS_WEIGHT_ENCODE;
    } else if (type == "figure") {
        encode_vector = FIGURE_WEIGHT_ENCODE;
    } else if (type == "dir") {
        encode_vector = DIRECTION_ENCODE;
    }

    for (int i = 0; i < encode_vector.size(); i++) {
        if (encode_vector[i] == c) return i;
    }
    return -1;
}

void deal_cards(string *p_card) {
    char dir;
    input_file >> dir;

    int curr_dir = (encode_char(dir, "dir") + 1) % 4;
    string card_info;

    for (int i = 0; i < 52; i++) {
        input_file >> card_info;
        p_card[13 * curr_dir + int(i / 4)] = card_info;

        curr_dir = (curr_dir + 1) % 4;
    }
}

int find_C3(string *p_card) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            if (p_card[13 * i + j] == "C3") return i;
        }
    }
    return -1;
}

void sort_card(string *p_card) {
    // auto-sort the cards using map
    for (int i = 0; i < 4; i++) {
        map<int, map<int, bool>> player_cards;

        for (int j = 0; j < 13; j++) {
            string card_info = p_card[13 * i + j];
            int suit = encode_char(card_info[0], "suit");
            int figure = encode_char(card_info[1], "figure");

            player_cards[suit][figure] = 1;
        }

        int curr_card = 0;
        for (auto [suit, figure_map] : player_cards) {
            for (auto [figure, existence] : figure_map) {
                string decoded_card_info = "";
                decoded_card_info += SUITS_WEIGHT_ENCODE[suit];
                decoded_card_info += FIGURE_WEIGHT_ENCODE[figure];

                p_card[13 * i + curr_card] = decoded_card_info;
                curr_card++;
            }
        }
    }
}

void show_card(string *p_card) {
    for (int i = 0; i < 4; i++) {
        output_file << DIRECTION_ENCODE[i] << ":";
        for (int j = 0; j < 13; j++) {
            output_file << " " << p_card[13 * i + j];
        }
        output_file << endl;
    }
}

void process_cmd(string *p_card) {
    int cmd;
    input_file >> cmd;

    if (cmd == 1) {
        output_file << DIRECTION_ENCODE[find_C3(p_card)] << endl;
    } else if (cmd == 2) {
        show_card(p_card);
    } else if (cmd == 3) {
        sort_card(p_card);
        show_card(p_card);
    }
}

int main() {
    string card[4][13];
    deal_cards(&card[0][0]);
    process_cmd(&card[0][0]);

    input_file.close();
    output_file.close();
}
