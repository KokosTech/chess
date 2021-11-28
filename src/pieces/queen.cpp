#include <Chess/Pieces/queen.hpp>

bool Queen::areSqrsValid(int x1, int y1, int x2, int y2, Piece* boardMove[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]){
    if (x1 == x2){
		int colOffset = (y2 - y1 > 0) ? 1 : -1;

		for (int checkCol = y1 + colOffset; checkCol != y2; checkCol = checkCol + colOffset){
			if (boardMove[x1][checkCol] != 0)
				return false;
		}

		return true;
	} else if (y2 == y1) {
		int rowOffset = (x2 - x1 > 0) ? 1 : -1;

		for (int checkRow = x1 + rowOffset; checkRow != x2; checkRow = checkRow + rowOffset){
			if (boardMove[checkRow][y1] != 0)
				return false;
		}

		return true;
	} else if ((y2 - y1 == x2 - x1) || (y2 - y1 == x1 - x2)) {
		int rowOffset = (x2 - x1 > 0) ? 1 : -1;
		int colOffset = (y2 - y1 > 0) ? 1 : -1;
		int checkRow;
		int checkCol;

		for (checkRow = x1 + rowOffset, checkCol = y1 + colOffset; checkRow != x2;
             checkRow += rowOffset, checkCol += colOffset){
			if (boardMove[checkRow][checkCol] != 0)
				return false;
		}
		
		return true;
	}
    
	return false;
}