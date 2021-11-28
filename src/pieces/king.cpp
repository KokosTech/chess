#include <Chess/Pieces/king.hpp>

bool King::areSqrsValid(int x1, int y1, int x2, int y2, Piece* boardMove[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]){
    int calcRow = x2 - x1;
	int calcDest = y2 - y1;
    
	if (((calcRow >= -1) && (calcRow <= 1)) && ((calcDest >= -1) && (calcDest <= 1))){return true;}

	return false;
}


