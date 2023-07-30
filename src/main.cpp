#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <map>

#include "ascii_board.hpp"

using namespace std;

enum {COLOR_TO_WRITE, DIRECTION_TO_TURN, NEXT_STATE};

typedef struct turmite {
    // row and column of the turmite
    pair<uint, uint> position;

    // direction to which the turmite is pointing
    // (UP: 0, RIGHT: 1, DOWN: 2, LEFT: 3)
    uint direction = 0;
    uint current_state = 0;
} turmite;

int main() {
    vector<vector<int>> turns = {{-1,  0},
                                 { 0,  1},
                                 { 1,  0},
                                 { 0, -1}};
    uint time_step = 0, total_steps = 0, turmite_number = 0;
    uint direction = 0, board_rows = 0, board_columns = 0;

    // Given a state and a color, the state transition table outputs a new
    // color, a change in direction and a new state
    map<pair<int, int>, vector<int>> state_table;
    state_table[make_pair(0, 0)] = {1, 1, 0};
    state_table[make_pair(0, 1)] = {1, 1, 1};
    state_table[make_pair(1, 0)] = {0, 0, 0};
    state_table[make_pair(1, 1)] = {0, 0, 1};

    // Creates the board, turmites and positions them on the board
    cin >> board_rows >> board_columns >> total_steps >> turmite_number;
    AsciiBoard board(board_rows, board_columns);
    board.set_draw_period(total_steps);

    vector<turmite> turmites(turmite_number);
    for (int i = 0; i < turmite_number; i++)
        cin >> turmites[i].position.first >> turmites[i].position.second;

    // Iterates over all steps performing the action of each turmite
    for (int time_step = 0; time_step < total_steps; time_step++) {
        for (turmite & turmite : turmites) {
            uint current_color = board.get_color(turmite.position.first, turmite.position.second);
            vector<int> transition = state_table[make_pair(turmite.current_state, current_color)];
            board.set_color(turmite.position.first, turmite.position.second, transition[COLOR_TO_WRITE]);
            direction = (direction + transition[DIRECTION_TO_TURN]) % 4;
            turmite.position.first  += turns[direction][0];
            turmite.position.second += turns[direction][1];
            turmite.position.first  %= board.get_rows();
            turmite.position.second %= board.get_columns();
            turmite.current_state = transition[NEXT_STATE];
        }
        if(board.is_active())
            board.draw(time_step + 1);
        else
            return 0;
    }
}
