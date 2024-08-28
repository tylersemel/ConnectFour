//represents connect 4 board, places checker piece, checks for winning conditions, detects draws
#include "board.hpp"
#include "player.hpp"

Board::Board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            Piece p{i, j, PieceColor::NONE};
            spaces[i][j] = p;
        }
    }
}

Piece Board::placePiece(int col, PieceColor color) {
    //check if row 5 is empty, if it is create and place piece
    //otherwise check row 4, and so on
    int row;

    for (int i = ROWS - 1; i >= 0; i--) {
        if (spaces[i][col].getColor() == PieceColor::NONE) {
            row = i;
            break;
        }
    }

    spaces[row][col].setColor(color);

    return spaces[row][col];
}
