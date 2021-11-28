#include <Chess/game.hpp>

void Game::getNames(){
    std::cout << "Enter player 1 (white) name: ";
    std::cin >> name1;
    std::cout << "Enter player 2 (black) name: ";
    std::cin >> name2;
    std::cout << "Press any key to start the game...\n";
    std::cin.get();
}

// We basically call this method to start the game

void Game::start(){
    getNames();    
    // Game Loop

    do{
        getMove(board.boardMove);
        alternateTurn();
    } while(!isOver());

    // End of game

    board.printBoard();
    std::cout << std::endl;
}

void Game::getMove(Piece* boardMove[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]){
    bool validMove = false;
    do{
        board.printBoard();
        int startX, startY, endX, endY;
        std::cout << "Enter the starting coordinates (x,y) for " << turnOf << ": ";
        std::cin >> startX >> startY;

        if(startX == -1 && startY == -1) // Use this to quit the game if you come to the point of killing yourself
            exit(0);

        std::cout << "Enter the ending coordinates (x,y) for " << turnOf << ": ";
        std::cin >> endX >> endY;

        // Check if the move is valid - PAINt - it could also be moved to a different method
        if ((startX >= 0 && startX <= DEFAULT_BOARD_SIZE - 1) && (startY >= 0 && startY <= DEFAULT_BOARD_SIZE - 1) && (endX >= 0 && endX <= DEFAULT_BOARD_SIZE - 1) && (endY >= 0 && endY <= DEFAULT_BOARD_SIZE - 1)){
            Piece* currentPiece = boardMove[startX][startY];
            if ((currentPiece != 0) && (currentPiece->getColor() == turnOf)){
                //std::cout << currentPiece->getPiece() << std::endl;
                if (currentPiece->isValidMove(startX, startY, endX, endY, boardMove)){
                    Piece* temp = boardMove[endX][endY];
                    boardMove[endX][endY] = boardMove[startX][startY];
                    boardMove[startX][startY] = 0;

                    //std::cout << board.isCheck(turnOf) << std::endl;
                    if (!board.isCheck(turnOf)){
                        delete temp;
                        validMove = true;
                    } else {
                        boardMove[startX][startY] = boardMove[endX][endY];
                        boardMove[endX][endY] = temp;
                    }
                }
            }
        }

        if (!validMove){
            std::cout << "Invalid move!\n";
        }
    } while (!validMove);
}

void Game::alternateTurn(){
    turnOf = (turnOf == WHITE_COLOR) ? BLACK_COLOR : WHITE_COLOR; // tbh, I could've used boolean for this, but it's kinda easier to read this way
}

bool Game::isOver(){
    bool __cantMove = !board.canMove(turnOf);
    if(__cantMove){
        if(board.isCheck(turnOf)){
            alternateTurn();
            std::cout << "Checkmate! " << ((turnOf == WHITE_COLOR) ? name1 : name2) << " is the winner!\n";
        } else {
            std::cout << "Stalemate!\n";
        }
    }
    return __cantMove;
}