#include <Chess/Pieces/bishop.hpp>

bool Bishop::areSqrsValid(int x1, int y1, int x2, int y2, Piece* boardMove[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]){
	if ((y2 - y1 == x2 - x1) || (y2 - y1 == x1 - x2)){

		int rowOffset = (x2 - x1 > 0) ? 1 : -1;
		int colOffset = (y2 - y1 > 0) ? 1 : -1;
		int checkRow;
		int checkCol;
		
		for (checkRow = x1 + rowOffset, checkCol = y1 + colOffset; checkRow != x2; checkRow += rowOffset, checkCol += colOffset) {
			if (boardMove[checkRow][checkCol] != 0)
				return false;
		}

		return true;
	}

	return false;
}