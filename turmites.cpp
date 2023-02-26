#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>

using namespace std;

enum {COLOR_TO_WRITE, DIRECTION_TO_TURN, NEXT_STATE};

typedef struct turmite {
    pair<uint, uint> position;
    uint direction = 0;
    uint current_state = 0;
} turmite;

void printBoard(vector<vector<int>> board) {
    vector<char> colors = {' ', '*'};
    for (auto i : board) {
        for (auto j : i)
            cout << colors[j];
        cout << endl;
    }
}

int main() {
    vector<vector<int>> turns = {{-1, 0},
                                 {0,  1},
                                 {1,  0},
                                 {0, -1}};
    uint direction = 0, time_step = 0, total_steps = 0, turmite_number = 0;
    uint board_rows = 0, board_columns = 0;

    map<pair<int, int>, vector<int>> state_table;
    state_table[make_pair(0, 0)] = {1, 1, 0};
    state_table[make_pair(0, 1)] = {1, 1, 1};
    state_table[make_pair(1, 0)] = {0, 0, 0};
    state_table[make_pair(1, 1)] = {0, 0, 1};

    cin >> board_rows >> board_columns >> total_steps >> turmite_number;
    vector<vector<int>> board(board_rows, vector<int> (board_columns, 0));
    vector<turmite> turmites(turmite_number);
    for (int i = 0; i < turmite_number; i++)
        cin >> turmites[i].position.first >> turmites[i].position.second;

    for (int time_step = 0; time_step < total_steps; time_step++) {
        for (turmite & turmite : turmites) {
            uint current_color = board[turmite.position.first][turmite.position.second];
            vector<int> transition = state_table[make_pair(turmite.current_state, current_color)];
            board[turmite.position.first][turmite.position.second] = transition[COLOR_TO_WRITE];
            direction = (direction + transition[DIRECTION_TO_TURN]) % 4;
            turmite.position.first  += turns[direction][0];
            turmite.position.second += turns[direction][1];
            turmite.position.first  %= board.size();
            turmite.position.second %= board[0].size();
            turmite.current_state = transition[NEXT_STATE];
        }
    }
    printBoard(board);
}
