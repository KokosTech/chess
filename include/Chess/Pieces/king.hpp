#pragma once

#include <Chess/Pieces/pieces.hpp>

class King : public Piece{
    private:
        virtual char getPiece() {return 'K';}
        bool areSqrsValid(int, int, int, int, Piece* boardMove[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]);
    public:
        King(char color) : Piece(color){}
        ~King(){}
};