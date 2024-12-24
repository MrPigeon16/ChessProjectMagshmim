#pragma once
#include "stdafx.h"
#include "Piece.h"
#include <string>
#include "Side.h"
#include <iostream>


/*

  - - - - - - - -
| r n b k q b n r |
| p p p p p p p p |
| # # # # # # # # |
| # # # # # # # # |
| # # # # # # # # |
| # # # # # # # # |
| p p p p p p p p |
| r n b k q b n r |
  - - - - - - - -

*/


enum GameMoves
{
    VALID_MOVE = 0,
    VALID_MOVE_CAUSED_CHECK = 1,
    INVALID_NO_PIECE_AT_SOURCE = 2,
    INVALID_DEST_OCCUPIED = 3,
    INVALID_CAUSES_SELF_CHECK = 4,
    INVALID_INDEX_OUT_OF_BOUNDS = 5,
    INVALID_ILLEGAL_MOVE = 6,
    INVALID_SOURCE_EQUALS_DEST = 7,
    VALID_CHECKMATE = 8
};


class Board
{
public:

    Board();
    ~Board();

    bool isWhiteTurn() const;
    bool isBlackTurn() const;
    std::string getBoardString() const;
    void setBoardString(const std::string newBoard);

    void printBoard() const;
    void eatPiece(const std::string position);
    bool isSquareTaken(const std::string position);
    std::string movePieceAtBoard(const std::string source, const std::string destination);
    void updateBoardString();
    Piece* createPiece(const std::string name, const std::string type, const std::string position);
    bool isKingChecked();
    bool isOneOfBlackPiecesCanReachLocationX(const std::string srcPosition, const std::string destPosition) const;
    bool isOneOfWhitePiecesCanReachLocationX(const std::string srcPosition, const std::string destPosition) const;
    bool isThereAnInterrupterPieceAtPath(std::string srcPosition, std::string destPosition) const;




private:
    std::string board;
    Side blackSide;
    Side whiteSide;


    void changeTurn();




};

