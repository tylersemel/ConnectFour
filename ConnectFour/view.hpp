#ifndef VIEW_H
#define VIEW_H

#include "board.hpp"
#include <iostream>
//where the board will be printed out
//red always goes first, player 1
class View {
public:
    void printBoard(const Board& board) const;
    // void promptMove(bool isRedTurn) const;

};

#endif