#pragma once
#include "stdafx.h"
#include "Piece.h"


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
    char* startGame();


private:
    




};

