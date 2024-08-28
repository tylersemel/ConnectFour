#ifndef GAME_H
#define GAME_H
#include "board.hpp"
#include "view.hpp"
#include "piece.hpp"
#include "player.hpp"

class GameManager {
public:
    GameManager();

    bool startGame(); //initialize the game
    bool getIsGameOver();
    int getWinningPlayer();
    Board getBoard();
    View getView();
    Player getCurrentPlayer();
    int turn = 1;

private:
    Board board;
    View view;
    bool isGameOver = false;
    int winningPlayer = 0;
    Player playerOne{PieceColor::X};
    Player playerTwo{PieceColor::O};

    bool hasConnectFour(Player& currentPlayer, Piece lastPlacedPiece);
};

#endif