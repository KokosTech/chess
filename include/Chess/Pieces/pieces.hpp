#pragma once
#include <iostream> // iostream has built-in equvilent of #pragma once

// Define default values for the board
#define DEFAULT_BOARD_SIZE 8
#define DEFAULT_BLACK_START_ROW DEFAULT_BOARD_SIZE - 1
#define DEFAULT_WHITE_START_ROW 0
#define WHITE_COLOR 'w'
#define BLACK_COLOR 'b'

class Piece {
    private:
        virtual bool areSqrsValid(int, int, int, int, Piece* board[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]) = 0;
        char pieceColor;
    public:
        Piece(char color) : pieceColor(color) {};
        virtual ~Piece() {};
        virtual char getPiece() = 0;
        char getColor();
        bool isValidMove(int, int, int, int, Piece* board[DEFAULT_BOARD_SIZE][DEFAULT_BOARD_SIZE]);
};
