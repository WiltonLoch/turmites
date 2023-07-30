#pragma once

#include <vector>

using namespace std;

class Board {
    public:
        Board(unsigned int rows, unsigned int columns);
        ~Board();

        virtual void draw(unsigned int current_iteration = 0) = 0;
        unsigned int get_rows();
        unsigned int get_columns();
        unsigned int get_color(unsigned int row, unsigned int column);
        void set_color(unsigned int row, unsigned int column, unsigned int color);
        void set_draw_period(unsigned int draw_period);
        bool is_active();

    protected:
        // board general color storage
        vector<vector<int>> tiles;

        // board dimensions
        unsigned int rows;
        unsigned int columns;

        // board dimensions
        bool active = 1;

        // period in number of steps for each drawing of the board
        unsigned int draw_period = 1;
};
