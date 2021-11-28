#pragma once

#include <Chess/Pieces/pieces.hpp>

class Knight : public Piece{
    private:
        virtual char getPiece(){return 'N';}
        bool areSqrsValid(int, int, int, int, Piece* boardMove[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]);
    public:
        Knight(char color) : Piece(color){}
        ~Knight(){}
};