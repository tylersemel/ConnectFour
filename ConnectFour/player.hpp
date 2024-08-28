// #pragma once

#ifndef PLAYER_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define PLAYER_H

#include "board.hpp"
#include "piece.hpp"
#include <vector>

class Player {
public:
    Player (const PieceColor color) : color(color) {}
    std::vector<Piece> pieces;
    PieceColor getColor() const;
    void addPiece(Piece& p);

private:
    PieceColor color = PieceColor::NONE;
};

#endif