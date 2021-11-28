#pragma once

#include <Chess/Pieces/pieces.hpp>

class Pawn : public Piece{
    private:
        virtual char getPiece(){return 'P';}
        bool areSqrsValid(int x1, int y1, int x2, int y2, Piece* boardMove[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]);
    public:
        Pawn(char color) : Piece(color){}
        ~Pawn(){}
};