#pragma once

#include <Chess/Pieces/pieces.hpp>

class Rook : public Piece{
    private:
        virtual char getPiece(){return 'R';}
        bool areSqrsValid(int, int, int, int, Piece* board[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]);
    public:
        Rook(char color) : Piece(color){}
        ~Rook(){}
};