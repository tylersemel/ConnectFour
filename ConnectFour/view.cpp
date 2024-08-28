#include "view.hpp"


void View::printBoard(const Board& board) const {
    for (int i = 0; i < board.COLS; i++) {
        std::cout << " " << i + 1 << " "; 
    }

    std::cout << std::endl;

    for (int i = 0; i < board.ROWS; i++) {
        for (int j = 0; j < board.COLS; j++) {

            switch(board.spaces[i][j].getColor()) {
                case PieceColor::X :
                    std::cout << " X ";
                    break;
                case PieceColor::O:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << " . ";
            }
        }

        std::cout << "" << std::endl;
    }
}