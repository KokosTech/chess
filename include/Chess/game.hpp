#pragma once
#include <iostream>
#include <Chess/board.hpp>
#include <Chess/Pieces/pieces.hpp>
class Game{
    private:
        Board board;
        char turnOf;
    protected:
        void getMove(Piece* boardMove[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]);
        void alternateTurn();
        std::string name1;
        std::string name2;
    public:
        Game() : turnOf(WHITE_COLOR) {}
        ~Game() {} // btw, i have to do this, because I get an error, I think we covered it in our Constructor / Destructor class / lesson
        void getNames();
        void start();
        bool isOver();
};