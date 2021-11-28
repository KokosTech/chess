cmake_minimum_required(VERSION 3.21)

project(chess)

include_directories(./include ./src)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable( chess_app
    ./src/main.cpp
    ./src/board.cpp
    ./src/game.cpp
    ./src/pieces/bishop.cpp
    ./src/pieces/king.cpp
    ./src/pieces/knight.cpp
    ./src/pieces/pawn.cpp
    ./src/pieces/pieces.cpp
    ./src/pieces/queen.cpp
    ./src/pieces/rook.cpp
)