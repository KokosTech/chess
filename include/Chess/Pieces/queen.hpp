#pragma once

#include <Chess/Pieces/pieces.hpp>

class Queen : public Piece{
    private:
        virtual char getPiece(){return 'Q';}
        bool areSqrsValid(int, int, int, int, Piece* board[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]);
    public:
        Queen(char color) : Piece(color){}
        ~Queen(){}
};