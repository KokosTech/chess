#include <Chess/board.hpp>

Board::Board(){
    for (int row = 0; row < DEFAULT_BOARD_SIZE; ++row)
		for (int col = 0; col < DEFAULT_BOARD_SIZE; ++col)
			boardMove[row][col] = NULL; // We can also use 0, since NULL is basically 0
    
	// I should've named the constants , maybe a bit shorter - but at least, I think it might be possible to use with bigger boards for whatever reason
	// Put the black pieces on their starting positions
	for (int col = 0; col < DEFAULT_BOARD_SIZE; ++col)
		boardMove[DEFAULT_BLACK_START_ROW - 1][col] = new Pawn(BLACK_COLOR);

	boardMove[DEFAULT_BLACK_START_ROW][0] = new Rook(BLACK_COLOR);
	boardMove[DEFAULT_BLACK_START_ROW][1] = new Knight(BLACK_COLOR);
	boardMove[DEFAULT_BLACK_START_ROW][2] = new Bishop(BLACK_COLOR);
	boardMove[DEFAULT_BLACK_START_ROW][3] = new Queen(BLACK_COLOR);
	boardMove[DEFAULT_BLACK_START_ROW][4] = new King(BLACK_COLOR);
	boardMove[DEFAULT_BLACK_START_ROW][5] = new Bishop(BLACK_COLOR);
	boardMove[DEFAULT_BLACK_START_ROW][6] = new Knight(BLACK_COLOR);
	boardMove[DEFAULT_BLACK_START_ROW][7] = new Rook(BLACK_COLOR);
	
    // Put the white pieces on their starting positions
	for (int col = 0; col < DEFAULT_BOARD_SIZE; ++col){
		boardMove[DEFAULT_WHITE_START_ROW + 1][col] = new Pawn(WHITE_COLOR);
	}
    
	boardMove[DEFAULT_WHITE_START_ROW][0] = new Rook(WHITE_COLOR);
	boardMove[DEFAULT_WHITE_START_ROW][1] = new Knight(WHITE_COLOR);
	boardMove[DEFAULT_WHITE_START_ROW][2] = new Bishop(WHITE_COLOR);
	boardMove[DEFAULT_WHITE_START_ROW][3] = new Queen(WHITE_COLOR);
	boardMove[DEFAULT_WHITE_START_ROW][4] = new King(WHITE_COLOR);
	boardMove[DEFAULT_WHITE_START_ROW][5] = new Bishop(WHITE_COLOR);
	boardMove[DEFAULT_WHITE_START_ROW][6] = new Knight(WHITE_COLOR);
	boardMove[DEFAULT_WHITE_START_ROW][7] = new Rook(WHITE_COLOR);
}

Board::~Board(){
	for (int row = 0; row < DEFAULT_BOARD_SIZE; ++row)
		for (int col = 0; col < DEFAULT_BOARD_SIZE; ++col)
			delete boardMove[row][col];
}

void Board::printBoard(){
	std::cout << "   ---------------------------------------" << std::endl;
	for (int row = DEFAULT_BOARD_SIZE - 1; row >= -1; --row){
		std::cout << (row > 0 ? row : 0) << " ";
		for (int col = 0; col < DEFAULT_BOARD_SIZE; ++col){
			if(row == -1){
				std::cout << "| 0" << col << " ";
				continue;
			}
			if (boardMove[row][col] == NULL)
				std::cout << "|    ";
			else{
				std::cout << "| " <<  boardMove[row][col]->getColor() << boardMove[row][col]->getPiece() << " ";
			}
		}
		std::cout << "|" << std::endl;
		std::cout << "   ---------------------------------------" << std::endl;
	}
}

bool Board::isCheck(char color){
	/* 	// Check if the king is in check
	for (int row = 0; row < DEFAULT_BOARD_SIZE; ++row)
		for (int col = 0; col < DEFAULT_BOARD_SIZE; ++col)
			if (boardMove[row][col] != NULL && boardMove[row][col]->getColor() != color)
				if (boardMove[row][col]->isValidMove(row, col, row, col))
					return true;
	return false; */

	// find the king - I screwed myself too much here, when I removed the {} - don't 
    int kingRow = 0;
    int kingCol = 0;

	for (int row = 0; row < DEFAULT_BOARD_SIZE; ++row){
		for (int col = 0; col < DEFAULT_BOARD_SIZE; ++col){
			if (boardMove[row][col] != 0){
                if (boardMove[row][col]->getColor() == color){
                    if (boardMove[row][col]->getPiece() == 'K'){
						kingRow = row;
						kingCol = col;
					}
				}
			}
		}
	}
    
	for (int row = 0; row < DEFAULT_BOARD_SIZE; ++row){
		for (int col = 0; col < DEFAULT_BOARD_SIZE; ++col){
			if (boardMove[row][col] != 0){
				if (boardMove[row][col]->getColor() != color){
					if (boardMove[row][col]->isValidMove(row, col, kingRow, kingCol, boardMove))
						return true;
				}
			}
		}
	}

	return false;
}

bool Board::canMove(char color){ // Don't comment on this, it soooo optimized
	for (int row = 0; row < DEFAULT_BOARD_SIZE; ++row){
		for (int col = 0; col < DEFAULT_BOARD_SIZE; ++col){
			if (boardMove[row][col] != 0){
                if (boardMove[row][col]->getColor() == color){
					for (int moveRow = 0; moveRow < DEFAULT_BOARD_SIZE; ++moveRow){
						for (int moveCol = 0; moveCol < DEFAULT_BOARD_SIZE; ++moveCol){
                            if (boardMove[row][col]->isValidMove(row, col, moveRow, moveCol, boardMove)){
								Piece* temp = boardMove[moveRow][moveCol];

								boardMove[moveRow][moveCol] = boardMove[row][col];
								boardMove[row][col] = 0;
								
                                bool boolCanMove = !isCheck(color);
                                
								boardMove[row][col] = boardMove[moveRow][moveCol];
								boardMove[moveRow][moveCol] = temp;
                                
								if (boolCanMove){
									return true;
								}
							}
						}
					}
				}
			}
		}
	}
	return false;
}