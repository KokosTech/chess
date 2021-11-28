#include <Chess/Pieces/pieces.hpp>

char Piece::getColor(){return pieceColor;}

bool Piece::isValidMove(int x1, int y1, int x2, int y2, Piece* boardMove[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]){
    Piece* dest = boardMove[x2][y2];
    
    if ((dest == NULL) || (pieceColor != dest->getColor()))
        return areSqrsValid(x1, y1, x2, y2, boardMove);
    
    return false;
}