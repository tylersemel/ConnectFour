#ifndef PIECE_HPP
#define PIECE_HPP

enum class PieceColor { NONE, X, O };

class Piece {
private:
    PieceColor color;
    int row;
    int col;
public:
    Piece(int row, int col, PieceColor color) : row(row), col(col), color(color) {}
    Piece() {}
    
    int getRow() const;
    int getCol() const;
    PieceColor getColor() const;
    void setColor(PieceColor color);

};

#endif