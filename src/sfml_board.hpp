#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "board.hpp"

using namespace std;

class SfmlBoard : public Board {
    public:
        SfmlBoard(unsigned int rows, unsigned int columns, unsigned int window_width, unsigned int window_height);
        ~SfmlBoard();

        void draw(unsigned int current_iteration = 0);
        void set_render_interval(float render_delay);
        float get_render_interval();

    private:
        float render_interval = 0.0;
        vector<sf::Color> colors;
        sf::RenderWindow* window;
        sf::RectangleShape tile;
        sf::Event event;
};
