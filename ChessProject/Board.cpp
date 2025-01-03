#include "Board.h"




Board::Board()
{
	this->blackSide = *(new Side());
	this->whiteSide = *(new Side());
	this->board = "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0";

	//which side is beginning.
	this->whiteSide.changeTurnState();

	/*
	adding rooks
	*/

	//black rooks
	Rook* rookBlackOne = new Rook("r", "Rook", "a8");
	Rook* rookBlackTwo = new Rook("r", "Rook", "h8");
	//white rooks
	Rook* rookWhiteOne = new Rook("R", "Rook", "a1");
	Rook* rookWhiteTwo = new Rook("R", "Rook", "h1");

	this->blackSide.addPiece(rookBlackOne);
	this->blackSide.addPiece(rookBlackTwo);

	this->whiteSide.addPiece(rookWhiteOne);
	this->whiteSide.addPiece(rookWhiteTwo);

	/*
	adding knights
	*/

	//black knights
	Knight* knightBlackOne = new Knight("k", "Knight", "b8");
	Knight* knightBlackTwo = new Knight("k", "Knight", "g8");

	//white knights
	Knight* knightWhiteOne = new Knight("K", "Knight", "b1");
	Knight* knightWhiteTwo = new Knight("K", "Knight", "g1");

	this->blackSide.addPiece(knightBlackOne);
	this->blackSide.addPiece(knightBlackTwo);

	this->whiteSide.addPiece(knightWhiteOne);
	this->whiteSide.addPiece(knightWhiteTwo);

	/*
	adding Queens
	*/
	Queen* blackQueen = new Queen("q", "Queen", "d8");
	Queen* whiteQueen = new Queen("Q", "Queen", "d1");

	this->whiteSide.addPiece(whiteQueen);
	this->blackSide.addPiece(blackQueen);

	/*
	adding bishops
	*/

	//black bishops
	Bishop* bishopBlackOne = new Bishop("b", "Bishop", "c8");
	Bishop* bishopBlackTwo = new Bishop("b", "Bishop", "f8");

	//white bishops
	Bishop* bishopWhiteOne = new Bishop("B", "Bishop", "c1");
	Bishop* bishopWhiteTwo = new Bishop("B", "Bishop", "f1");

	this->blackSide.addPiece(bishopBlackOne);
	this->blackSide.addPiece(bishopBlackTwo);

	this->whiteSide.addPiece(bishopWhiteOne);
	this->whiteSide.addPiece(bishopWhiteTwo);

	/*
	adding kings
	*/

	//black king
	King* blackKing = new King("k", "King", "e8");

	//white king
	King* whiteKing = new King("K", "King", "e1");

	this->blackSide.addPiece(blackKing);
	this->whiteSide.addPiece(whiteKing);

	/*
	adding pawns
	*/

	//black pawns
	Pawn* blackPawnOne = new Pawn("p", "Pawn", "a7");
	Pawn* blackPawnTwo = new Pawn("p", "Pawn", "b7");
	Pawn* blackPawnThree = new Pawn("p", "Pawn", "c7");
	Pawn* blackPawnFour = new Pawn("p", "Pawn", "d7");
	Pawn* blackPawnFive = new Pawn("p", "Pawn", "e7");
	Pawn* blackPawnSix = new Pawn("p", "Pawn", "f7");
	Pawn* blackPawnSeven = new Pawn("p", "Pawn", "g7");
	Pawn* blackPawnEight = new Pawn("p", "Pawn", "h7");

	//white pawns
	Pawn* whitePawnOne = new Pawn("P", "Pawn", "a2");
	Pawn* whitePawnTwo = new Pawn("P", "Pawn", "b2");
	Pawn* whitePawnThree = new Pawn("P", "Pawn", "c2");
	Pawn* whitePawnFour = new Pawn("P", "Pawn", "d2");
	Pawn* whitePawnFive = new Pawn("P", "Pawn", "e2");
	Pawn* whitePawnSix = new Pawn("P", "Pawn", "f2");
	Pawn* whitePawnSeven = new Pawn("P", "Pawn", "g2");
	Pawn* whitePawnEight = new Pawn("P", "Pawn", "h2");

	this->blackSide.addPiece(blackPawnOne);
	this->blackSide.addPiece(blackPawnTwo);
	this->blackSide.addPiece(blackPawnThree);
	this->blackSide.addPiece(blackPawnFour);
	this->blackSide.addPiece(blackPawnFive);
	this->blackSide.addPiece(blackPawnSix);
	this->blackSide.addPiece(blackPawnSeven);
	this->blackSide.addPiece(blackPawnEight);

	this->whiteSide.addPiece(whitePawnOne);
	this->whiteSide.addPiece(whitePawnTwo);
	this->whiteSide.addPiece(whitePawnThree);
	this->whiteSide.addPiece(whitePawnFour);
	this->whiteSide.addPiece(whitePawnFive);
	this->whiteSide.addPiece(whitePawnSix);
	this->whiteSide.addPiece(whitePawnSeven);
	this->whiteSide.addPiece(whitePawnEight);


}

bool Board::isWhiteTurn() const
{
	return this->whiteSide.isItSideTurn();
}

bool Board::isBlackTurn() const
{
	return this->blackSide.isItSideTurn();
}

string Board::getBoardString() const
{
	return this->board;
}

void Board::printBoard() const
{
	//since the board starts from the white at the frontend and except the sending to the frontend I refer to this string as if black is the bottom one, i print it reveresed.
	for (int i = 63; i >= 0; i--)
	{
		std::cout << getBoardString()[i] << " ";

		if (i % 8 == 0 && i != 0)
		{
			std::cout << std::endl;
		}
	}

	std::cout << std::endl;
}

void Board::eatPiece(const string position)
{
	if (isWhiteTurn())
	{
		if (this->blackSide.isOneOfMyPiecesAtXLocation(position))
		{
			this->blackSide.removePiece(position);
		}
	}
	else
	{
		if (this->whiteSide.isOneOfMyPiecesAtXLocation(position))
		{
			this->whiteSide.removePiece(position);
		}
	}
}

bool Board::isSquareTaken(const string position)
{
	return blackSide.isOneOfMyPiecesAtXLocation(position) || whiteSide.isOneOfMyPiecesAtXLocation(position);
}


string Board::movePieceAtBoard(const string source, const string destination)
{
	string retString;

	if (isWhiteTurn())
	{
		if (blackSide.isOneOfMyPiecesAtXLocation(source))
		{
			return to_string(INVALID_NO_PIECE_AT_SOURCE);
		}

		if (!whiteSide.isOneOfMyPiecesAtXLocation(source))
		{
			return to_string(INVALID_NO_PIECE_AT_SOURCE);
		}

		if (!isOneOfBlackPiecesCanReachLocationX(source, destination) && whiteSide.getPieceAtLocationX(source)->getType() != "Knight")
		{
			return to_string(INVALID_ILLEGAL_MOVE);
		}

		if (whiteSide.getPieceAtLocationX(source)->getName() == "P")
		{
			if (whiteSide.getPieceAtLocationX(source)->isItFirstMove() && blackSide.isOneOfMyPiecesAtXLocation(destination) && !whiteSide.isLegitEatingMoveForPawn(source, destination, "P"))
			{
				return to_string(INVALID_ILLEGAL_MOVE);
			}
		}
		bool flagForPawn = whiteSide.getPieceAtLocationX(source)->isLegitMove(destination);
		retString = whiteSide.movePiece(source, destination);


		if (blackSide.isOneOfMyPiecesAtXLocation(destination) && retString == "0" && whiteSide.getPieceAtLocationX(destination)->getName() != "p")
		{
			//if the eating isn't preventing check i will remake the piece.
			Piece* tempPiece = blackSide.getPieceAtLocationX(destination);
			string name, type, position;
			name = tempPiece->getName();
			type = tempPiece->getType();
			position = tempPiece->getPosition();

			eatPiece(destination);

			if (isKingChecked())
			{
				//forcing pawn back
				whiteSide.getPieceAtLocationX(destination)->setPosition(source);
				//adding the piece back
				blackSide.addPiece(createPiece(name, type, position));
				retString = to_string(INVALID_CAUSES_SELF_CHECK);
				return retString;
			}
		}

		if (isKingChecked() && retString == "0")
		{
			whiteSide.movePiece(destination, source);
			retString = to_string(INVALID_CAUSES_SELF_CHECK);
			return retString;
		}
	}
	else
	{
		//black side's moving code. same as white.

		if (whiteSide.isOneOfMyPiecesAtXLocation(source))
		{
			return to_string(INVALID_NO_PIECE_AT_SOURCE);
		}

		if (!blackSide.isOneOfMyPiecesAtXLocation(source))
		{
			return to_string(INVALID_NO_PIECE_AT_SOURCE);
		}

		if (!isOneOfBlackPiecesCanReachLocationX(source, destination) && blackSide.getPieceAtLocationX(source)->getType() != "Knight")
		{
			return to_string(INVALID_ILLEGAL_MOVE);
		}

		if (blackSide.getPieceAtLocationX(source)->getName() == "p")
		{
			if (blackSide.getPieceAtLocationX(source)->isItFirstMove() && whiteSide.isOneOfMyPiecesAtXLocation(destination) && !blackSide.isLegitEatingMoveForPawn(source, destination, "p"))
			{
				return to_string(INVALID_ILLEGAL_MOVE);
			}
		}
		bool flagForPawn = blackSide.getPieceAtLocationX(source)->isLegitMove(destination);
		retString = blackSide.movePiece(source, destination);


		if (whiteSide.isOneOfMyPiecesAtXLocation(destination) && retString == "0" && blackSide.getPieceAtLocationX(destination)->getName() != "P")
		{
			//if the eating isn't preventing check i will remake the piece.
			Piece* tempPiece = whiteSide.getPieceAtLocationX(destination);
			string name, type, position;
			name = tempPiece->getName();
			type = tempPiece->getType();
			position = tempPiece->getPosition();

			eatPiece(destination);

			if (isKingChecked())
			{
				//forcing pawn back
				blackSide.getPieceAtLocationX(destination)->setPosition(source);
				//adding the piece back
				whiteSide.addPiece(createPiece(name, type, position));
				retString = to_string(INVALID_CAUSES_SELF_CHECK);
				return retString;
			}
		}

		if (isKingChecked() && retString == "0")
		{
			blackSide.movePiece(destination, source);
			retString = to_string(INVALID_CAUSES_SELF_CHECK);
			return retString;
		}

	}

	if (retString == "0" || retString == "1" || retString == "8")	//if move was legit.
	{
		changeTurn();	//changes turn
	}

	return retString;
}


void Board::updateBoardString()
{
	string newBoardStr = this->board;
	string currPos = "xx";

	for (int i = 0; i < 64; i++)
	{
		currPos[0] = (char)i % 8 + 97;
		currPos[1] = to_string((int)(i / 8) + 1)[0];

		if (this->whiteSide.isOneOfMyPiecesAtXLocation(currPos))
		{
			newBoardStr[i] = this->whiteSide.getPieceAtLocationX(currPos)->getName()[0];
		}
		else if (this->blackSide.isOneOfMyPiecesAtXLocation(currPos))
		{
			newBoardStr[i] = this->blackSide.getPieceAtLocationX(currPos)->getName()[0];
		}
		else
		{
			newBoardStr[i] = '#';
		}
	}

	setBoardString(newBoardStr);
}

void Board::setBoardString(const string newBoard)
{
	this->board = newBoard;
}

void Board::changeTurn()
{
	this->blackSide.changeTurnState();
	this->whiteSide.changeTurnState();
}


bool Board::isKingChecked()
{
	if (isWhiteTurn())
	{
		if (blackSide.isOneOfMyPiecesCanReachXLocation(whiteSide.getKingLocation()))
		{
			this->whiteSide.setCheckState(true);
			return true;
		}
		else
		{
			this->whiteSide.setCheckState(false);
		}
	}
	else
	{
		if (whiteSide.isOneOfMyPiecesCanReachXLocation(blackSide.getKingLocation()))
		{
			this->whiteSide.setCheckState(true);
			return true;
		}
		else
		{
			this->whiteSide.setCheckState(false);
		}
	}

	return false;
}

Piece* Board::createPiece(const string name, const string type, const string position)
{
	if (type == "Rook")
	{
		Rook* newRook = new Rook(name, type, position);
		return newRook;
	}
	if (type == "Queen")
	{
		Queen* newQueen = new Queen(name, type, position);
		return newQueen;
	}
	if (type == "Bishop")
	{
		Bishop* newBishop = new Bishop(name, type, position);
		return newBishop;
	}
	if (type == "Pawn")
	{
		Pawn* newPawn = new Pawn(name, type, position);
		return newPawn;
	}

	if (type == "Knight")
	{
		Knight* newKnight = new Knight(name, type, position);
		return newKnight;
	}
}

bool Board::isOneOfBlackPiecesCanReachLocationX(const string srcPosition, const string destPosition) const
{
	return this->blackSide.isOneOfMyPiecesCanReachXLocation(destPosition) && !isThereAnInterrupterPieceAtPath(srcPosition, destPosition);
}

bool Board::isOneOfWhitePiecesCanReachLocationX(const string srcPosition, const string destPosition) const
{
	return this->whiteSide.isOneOfMyPiecesCanReachXLocation(destPosition) && !isThereAnInterrupterPieceAtPath(srcPosition, destPosition);
}

bool Board::isThereAnInterrupterPieceAtPath(string srcPosition, string destPosition) const
{
	int srcValue = srcPosition[0] + srcPosition[1];
	int dstValue = destPosition[0] + destPosition[1];

	if (destPosition > srcPosition)		//going forward or backward.
	{
		if (srcPosition[0] == destPosition[0])	//if the move is a horizontal one 
		{
			while (destPosition[1] > srcPosition[1])
			{
				destPosition[1] = destPosition[1] - 1;	//this runs first so the function won't check the destination (because it possible to have a piece there to eat)

				if (destPosition != srcPosition)	//if not source.
				{
					if (whiteSide.isOneOfMyPiecesAtXLocation(destPosition) || blackSide.isOneOfMyPiecesAtXLocation(destPosition))	//checks if a piece is between.
					{
						return true;
					}
				}
			}
		}

		if (srcPosition[1] == destPosition[1])	//if the move is vertical one.
		{
			while (destPosition[0] > srcPosition[0])
			{
				destPosition[0] = destPosition[0] - 1;

				if (destPosition != srcPosition)
				{
					if (whiteSide.isOneOfMyPiecesAtXLocation(destPosition) || blackSide.isOneOfMyPiecesAtXLocation(destPosition))
					{
						return true;
					}
				}
			}
		}

		if (srcPosition[0] != destPosition[0] && srcPosition[1] != destPosition[1])	//if the move is a diagonal one.
		{
			while (destPosition[0] > srcPosition[0] && destPosition[1] > srcPosition[1])
			{
				destPosition[0] = destPosition[0] - 1;
				destPosition[1] = destPosition[1] - 1;

				if (destPosition != srcPosition)
				{
					if (whiteSide.isOneOfMyPiecesAtXLocation(destPosition) || blackSide.isOneOfMyPiecesAtXLocation(destPosition))
					{
						return true;
					}
				}
			}
		}
	}
	else     //if the move is forward
	{
		if (srcPosition[0] == destPosition[0])
		{
			while (destPosition[1] < srcPosition[1])
			{
				srcPosition[1] = srcPosition[1] - 1;

				if (destPosition != srcPosition)
				{
					if (whiteSide.isOneOfMyPiecesAtXLocation(srcPosition) || blackSide.isOneOfMyPiecesAtXLocation(srcPosition))
					{
						return true;
					}
				}
			}
		}

		if (srcPosition[1] == destPosition[1])
		{
			while (destPosition[0] < srcPosition[0])
			{
				srcPosition[0] = srcPosition[0] - 1;

				if (destPosition != srcPosition)
				{
					if (whiteSide.isOneOfMyPiecesAtXLocation(srcPosition) || blackSide.isOneOfMyPiecesAtXLocation(srcPosition))
					{
						return true;
					}
				}
			}
		}

		if (srcPosition[0] != destPosition[0] && srcPosition[1] != destPosition[1])
		{
			while (destPosition[0] < srcPosition[0] && destPosition[1] < srcPosition[1])
			{
				srcPosition[0] = srcPosition[0] - 1;
				srcPosition[1] = srcPosition[1] - 1;

				if (destPosition != srcPosition)
				{
					if (whiteSide.isOneOfMyPiecesAtXLocation(srcPosition) || blackSide.isOneOfMyPiecesAtXLocation(srcPosition))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}



Board::~Board()
{

}


