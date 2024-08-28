#include "player.hpp"
#include <iostream>



PieceColor Player::getColor() const {
    return Player::color;
}

void Player::addPiece(Piece& p)
{
    pieces.push_back(p);
}
