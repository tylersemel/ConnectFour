#include "piece.hpp"

int Piece::getRow() const {
    return row;
}

int Piece::getCol() const {
    return col;
}

PieceColor Piece::getColor() const {
    return color;
}

void Piece::setColor(PieceColor color)
{
    this->color = color;
}
