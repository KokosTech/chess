#include <Chess/Pieces/pawn.hpp>

bool Pawn::areSqrsValid(int x1, int y1, int x2, int y2, Piece* boardMove[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]){
/*     if(x1 == x2 && y1 == y2){
        return false;
    }
    if(x1 == x2 && y1 == y2 + 1){
        return true;
    }
    if(x1 == x2 && y1 == y2 - 1){
        return true;
    }
    if(x1 == x2 + 1 && y1 == y2 + 1){
        return true;
    }
    if(x1 == x2 - 1 && y1 == y2 + 1){
        return true;
    }
    return false; */

	// This is where all my problems came from - at least a few hours debugging

    Piece* dest = boardMove[x2][y2];
	
	if (dest == NULL){
		//std::cout << getColor() << "x2x1: " << x2 << x1 << std::endl;
		if (y1 == y2){
            if (getColor() == WHITE_COLOR){
				//std::cout << getColor() << "==w\n";
				if (x2 == x1 + 1){
					return true;
				}
			} else {
				//std::cout << "jjjjjj" << "x2x1: " << x2 << x1 << std::endl;
				if (x2 == x1 - 1)
					return true;
			}
		}
	} else {
		if ((y1 == y2 + 1) || (y1 == y2 - 1)){
            if (getColor() == WHITE_COLOR){
				if (x2 == x1 + 1)
					return true;
			} else {
				if (x2 == x1 - 1)
					return true;
			}
		} else {
/* 			if (getColor() == WHITE_COLOR){
				if (x2 == x1 + 2){
					if (y1 == 1){
						if (boardMove[x2][y2] == NULL){
							return true;
						}
					}
				}
			} else {
				if (x2 == x1 - 2){
					if (y1 == 6){
						if (boardMove[x2][y2] == NULL){
							return true;
						}
					}
				}
			} */

			// And this one here

			if (getColor() == WHITE_COLOR){
				//std::cout << getColor() << "==w\n";
				if (x2 == x1 + 1){
					return true;
				}
			} else {
				//std::cout << "jjjjjj" << "x2x1: " << x2 << x1 << std::endl;
				if (x2 == x1 - 1)
					return true;
			}
		}
	}

	return false;
}