#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <chrono>

#include "sfml_board.hpp"

using namespace std;

SfmlBoard::SfmlBoard (unsigned int rows, unsigned int columns, unsigned int window_width, unsigned int window_height) : Board(rows, columns) {
    colors = { sf::Color(0, 0, 0, 255), sf::Color(255, 255, 255, 255) };
    window = new sf::RenderWindow(sf::VideoMode(window_width, window_height), "Turmites");
    tile = sf::RectangleShape(sf::Vector2f( (float) window_width/columns, (float) window_height/rows));
}

SfmlBoard::~SfmlBoard () {
    delete window;
}

void SfmlBoard::set_render_interval(float render_interval) {
    this->render_interval = render_interval;
};

float SfmlBoard::get_render_interval() {
    return render_interval;
};

void SfmlBoard::draw(unsigned int current_iteration) {
    if(draw_period > 1 && current_iteration % draw_period != 0) return;

    sf::Vector2f tile_size = tile.getSize();

    window->clear();

    // Needs to be improved, perhaps using CSR with color index instead of a plain "tilemap"
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++){
            tile.setPosition(j * tile_size.x, i * tile_size.y);
            tile.setFillColor(colors[tiles[i][j]]);
            window->draw(tile);
        }
    }

    std::chrono::duration<double> elapsed_time;
    auto start = std::chrono::steady_clock::now();
    do {
        while (window->pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window->close();
        }
        auto end = std::chrono::steady_clock::now();
        elapsed_time = end - start;
    } while (elapsed_time.count() < render_interval);

    window->display();
    active = window->isOpen();
}
