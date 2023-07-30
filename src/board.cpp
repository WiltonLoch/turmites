#include "board.hpp"

Board::Board (unsigned int rows, unsigned int columns) : rows(rows), columns(columns) {
    tiles = vector<vector<int>> (rows, vector<int> (columns, 0));
}
Board::~Board () {}

unsigned int Board::get_rows() { return rows; }
unsigned int Board::get_columns() { return columns; }
unsigned int Board::get_color(unsigned int row, unsigned int column) { return tiles[row][column]; }
void Board::set_draw_period(unsigned int draw_period) { this->draw_period = draw_period; };
void Board::set_color(unsigned int row, unsigned int column, unsigned int color) { tiles[row][column] = color; }
bool Board::is_active() { return active; }
