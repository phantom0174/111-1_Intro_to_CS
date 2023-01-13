/*
Assignment 14
Name: 蕭登鴻
Student Number: 111502552
Course 2022-CE1001-B
*/

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// chinese, english, math, science
int SCORE_STANDARDS[4] = { 12, 12, 8, 12 };

map<string, int> NAME_TO_INDEX = {
    { "chinese", 0 },
    { "english", 1 },
    { "math", 2 },
    { "science", 3 }
};

map<string, vector<int>> students_score;

ifstream input_file("./score.txt", ios::in);
ofstream output_file("./output.txt", ios::out);
ifstream cmd_file("./cmd.txt", ios::in);

void read_and_output_file() {
    string name;
    while (input_file >> name) {
        vector<int> scores;
        int score;

        bool pass = true;
        for (int i = 0; i < 4; i++) {
            input_file >> score;
            scores.push_back(score);
            if (score < SCORE_STANDARDS[i]) pass = false;
        }
        students_score[name] = scores;

        if (pass) {
            output_file << "Hello " << name << ", welcome to NCU CSIE!" << endl;
        } else {
            output_file << "Sorry, " << name << " can't enter NCU CSIE." << endl;
        }
    }
}

void process_cmd() {
    string name, subject;
    while (cmd_file >> name >> subject) {
        if (students_score.find(name) != students_score.end() && NAME_TO_INDEX.find(subject) != NAME_TO_INDEX.end()) {
            output_file << students_score[name][NAME_TO_INDEX[subject]] << endl;
        } else {
            output_file << "Error." << endl;
        }
    }
}

int main() {
    read_and_output_file();
    process_cmd();

    input_file.close();
    output_file.close();
    cmd_file.close();
}
