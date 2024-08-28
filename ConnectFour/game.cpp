//manages game flow, initializes board, handles player turns, determines game outcomes
#include "game.hpp"
#include <iostream>
#include <vector>

GameManager::GameManager() {
    board = Board{};
    view = View{};
}

bool GameManager::startGame() {
    
    while (!isGameOver && turn < (board.ROWS * board.COLS)) {
        int col = -1;
        Player* currentPlayer = &playerOne; //initializing the current player

        std::cout << std::endl;
        view.printBoard(board);

        std::cout << "Player ";

        std::string player_num = "1";

        if (getCurrentPlayer().getColor() == PieceColor::X) {
            currentPlayer = &playerOne;
            std::cout << player_num;
        }
        else {
            currentPlayer = &playerTwo;
            player_num = "2";
            std::cout << player_num;
        }

        std::cout << "'s turn." << std::endl;
        std::cout << "Column to place piece: ";
        std::cin >> col;

        //checking that the column the user enters is not out of bounds
        //otherwise ask again
        while (col <= 0 || col > 7 || (col >= 1 && col <= 7 && board.spaces[0][col - 1].getColor() != PieceColor::NONE)) {
            std::cout << "Try again." << std::endl;
            std::cout << "Column to place piece: ";
            std::cin >> col;
        }

        Piece p = board.placePiece(col - 1, currentPlayer->getColor());
        currentPlayer->addPiece(p);

        bool connectFour = hasConnectFour(*currentPlayer, p);

        if (connectFour) {
            view.printBoard(board);
            std::cout << std::endl;
            std::cout << "Player " << player_num << " wins!" << std::endl;
            isGameOver = true;
        }

        turn++;
    }

    return true;
}

bool GameManager::getIsGameOver()
{
    return isGameOver;
}

int GameManager::getWinningPlayer()
{
    return winningPlayer;
}

Board GameManager::getBoard()
{
    return board;
}

View GameManager::getView()
{
    return view;
}

Player GameManager::getCurrentPlayer()
{   
    //if the number of turns is even return player two
    //since player one starts first, will always be on odd turns
    if (turn % 2 == 0) {
        return playerTwo;
    }

    return playerOne;
}

/**
 * Check the last place piece from the last player's turn. If the piece is a connect four, return true.
 * So need to check, left, diagonals
 */
bool GameManager::hasConnectFour(Player& currentPlayer, Piece lastPiece) {
    int horizontal = 1;
    int diagonal = 1;
    int vertical = 1;
    
    for (int i = 1; i < 4; i++) {
        if (lastPiece.getRow() <= board.ROWS - 4 && board.spaces[lastPiece.getRow() + i][lastPiece.getCol()].getColor() == currentPlayer.getColor()) { //down
            vertical++;
        }
        if (lastPiece.getRow() >= 3 && board.spaces[lastPiece.getRow() - i][lastPiece.getCol()].getColor() == currentPlayer.getColor()) { //up
            vertical++;
        }
        if (lastPiece.getRow() <= board.ROWS - 4 && lastPiece.getCol() <= board.COLS - 4 && board.spaces[lastPiece.getRow() + i][lastPiece.getCol() + i].getColor() == currentPlayer.getColor()) { //down right diagonal
            diagonal++;
        }
        if (lastPiece.getRow() >= 3 && lastPiece.getCol() >= 3 && board.spaces[lastPiece.getRow() - i][lastPiece.getCol() - i].getColor() == currentPlayer.getColor()) { //up left diagonal
            diagonal++;
        }
        if (lastPiece.getRow() >= 3 && lastPiece.getCol() <= board.COLS - 4 && board.spaces[lastPiece.getRow() - i][lastPiece.getCol() + i].getColor() == currentPlayer.getColor()) { //up right diagonal
            diagonal++;
        }
        if (lastPiece.getRow() <= board.ROWS - 4 && lastPiece.getCol() >= 3 && board.spaces[lastPiece.getRow() + i][lastPiece.getCol() - i].getColor() == currentPlayer.getColor()) { //left down diagonal
            diagonal++;
        }
        if (lastPiece.getCol() <= board.COLS - 4 && board.spaces[lastPiece.getRow()][lastPiece.getCol() + i].getColor() == currentPlayer.getColor()) { //right
            horizontal++;
        }
        if (lastPiece.getCol() >= 3 && board.spaces[lastPiece.getRow()][lastPiece.getCol() - i].getColor() == currentPlayer.getColor()) { //left
            horizontal++;
        }
    }

    return horizontal >= 4 || diagonal >= 4 || vertical >= 4;
}


