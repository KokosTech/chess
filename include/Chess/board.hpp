#pragma once

// Include some global libraries

#include <iostream>

// Include, basically, every piece:
#include <Chess/Pieces/bishop.hpp>
#include <Chess/Pieces/king.hpp>
#include <Chess/Pieces/knight.hpp>
#include <Chess/Pieces/pawn.hpp>
#include <Chess/Pieces/queen.hpp>
#include <Chess/Pieces/rook.hpp>

class Board{
    private:
    public:
        Board();
        ~Board();
        void printBoard();
        bool canMove(char color);
        bool isCheck(char color);
        Piece* boardMove[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE];
};