#pragma once

#include <vector>

#include "board.hpp"

using namespace std;

class AsciiBoard : public Board {
    public:
        AsciiBoard(unsigned int rows, unsigned int columns);
        ~AsciiBoard();

        void draw(unsigned int current_iteration = 0);

    private:
        //store the "colors" to be printed
        vector<char> colors;
};
