#include <iostream>

#include "ascii_board.hpp"

using namespace std;

AsciiBoard::AsciiBoard (unsigned int rows, unsigned int columns) : Board(rows, columns) {
    colors = {' ', '*'};
}

AsciiBoard::~AsciiBoard () {}

void AsciiBoard::draw(unsigned int current_iteration) {
    if(draw_period > 1 && current_iteration % draw_period != 0) return;

    for (auto i : tiles) {
        for (auto j : i)
            cout << colors[j];
        cout << endl;
    }
}
