#pragma once

#include <Chess/Pieces/pieces.hpp>

class Bishop : public Piece {
  private:
    virtual char getPiece() {return 'B';}
    bool areSqrsValid(int, int, int, int, Piece* boardMove[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]);
  public:
    Bishop(char color) : Piece(color) {}
    ~Bishop() {}
};
