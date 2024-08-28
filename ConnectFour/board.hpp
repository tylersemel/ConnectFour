#ifndef BOARD_H
#define BOARD_H

#include "piece.hpp"

class Board {
public:
    Board();
    static const int ROWS = 6;
    static const int COLS = 7;
    Piece spaces[ROWS][COLS];
    Piece placePiece(int col, PieceColor color);

};

#endif