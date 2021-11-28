#include <Chess/Pieces/knight.hpp>

bool Knight::areSqrsValid(int x1, int y1, int x2, int y2, Piece* boardMove[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]){
/*     if(newX < 0 || newX > 7 || newY < 0 || newY > 7){
        return false;
    }
    if(boardMove[newX][newY] != nullptr){
        if(boardMove[newX][newY]->getColor() == this->getColor()){
            return false;
        }
    }
    if(abs(x - newX) == 1 && abs(y - newY) == 2){
        return true;
    }
    if(abs(x - newX) == 2 && abs(y - newY) == 1){
        return true;
    }
    return false; */

    if ((y1 == y2 + 1) || (y1 == y2 - 1))
		if ((x1 == x2 + 2) || (x1 == x2 - 2))
			return true;

	if ((y1 == y2 + 2) || (y1 == y2 - 2))
		if ((x1 == x2 + 1) || (x1 == x2 - 1))
			return true;

	return false;
}
