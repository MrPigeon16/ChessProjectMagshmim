#pragma once


#include "Bishop.h"
#include "Rook.h"
#include "King.h"
#include "Pawn.h"
#include "Queen.h"
#include "Knight.h"

#include <vector>

class Side
{
public:
	Side();
	void addPiece(Piece* newPiece);
	void removePiece(const std::string position);

	std::vector<Piece*> getPiecesVector() const;
	Piece* getPieceAtLocationX(const std::string location) const;
	std::string getKingLocation() const;
	bool isItSideTurn() const;

	void changeTurnState();

	std::string movePiece(const std::string sourcePosition, const std::string destinationPosition);
	Side operator=(Side& otherSide);

	bool isOneOfMyPiecesAtXLocation(const std::string location) const;
	bool isOneOfMyPiecesCanReachXLocation(const std::string location) const;
	void setCheckState(const bool check);
	bool isLegitEatingMoveForPawn(const std::string source, const std::string destination, const std::string name);





private:
	std::vector<Piece*> Pieces;
	bool thisSideTurn;
	bool isChecked;
};
