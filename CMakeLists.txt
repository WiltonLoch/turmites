cmake_minimum_required(VERSION 3.20)
project(turmites)

SET(SRCS src/board.cpp src/sfml_board.cpp src/ascii_board.cpp src/main.cpp)

add_executable(turmites ${SRCS})
target_link_libraries(turmites sfml-graphics sfml-window sfml-system)
