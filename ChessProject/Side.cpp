#include "Side.h"

Side::Side()
{
	this->thisSideTurn = false;
	this->isChecked = false;
}

void Side::addPiece(Piece* newPiece)
{
	this->Pieces.push_back(newPiece);
}

void Side::removePiece(const std::string position)
{

	for (int i = 0; i < this->Pieces.size(); i++)//running on al the pieces in the vector
	{
		Piece* currPiece = getPiecesVector()[i];
		if (currPiece->getPosition() == position)//until we get the one that we want to remove
		{
			this->Pieces.erase(this->Pieces.begin() + i);
			i = this->Pieces.size();
		}
	}
}

std::vector<Piece*> Side::getPiecesVector() const
{
	return this->Pieces;
}

void Side::changeTurnState()
{
	this->thisSideTurn = !this->thisSideTurn;
}

bool Side::isItSideTurn() const
{
	return this->thisSideTurn;
}

bool Side::isOneOfMyPiecesAtXLocation(const std::string location) const
{
	for (int i = 0; i < this->Pieces.size(); i++)//running for all the pieces in the vector
	{
		if (this->Pieces[i]->getPosition() == location)//if somethin is in the location that we wish for -> return true
		{
			return true;
		}
	}
	return false;
}

Side Side::operator=(Side& otherSide)
{
	this->Pieces = otherSide.getPiecesVector();
	this->thisSideTurn = otherSide.isItSideTurn();
	return *this;
}


Piece* Side::getPieceAtLocationX(const std::string location) const
{
	for (int i = 0; i < this->Pieces.size(); i++)
	{
		if (this->Pieces[i]->getPosition() == location)
		{
			return this->Pieces[i];
		}
	}
}


std::string Side::movePiece(const std::string sourcePosOfPiece, const std::string destinationPosOfPiece)
{
	std::string returnString = std::to_string(INVALID_NO_PIECE_AT_SOURCE);

	if (isOneOfMyPiecesAtXLocation(destinationPosOfPiece))
	{
		return std::to_string(INVALID_DEST_OCCUPIED);
	}

	if (isOneOfMyPiecesAtXLocation(sourcePosOfPiece))
	{
		Piece* pieceAtXLocation = getPieceAtLocationX(sourcePosOfPiece);
		returnString = pieceAtXLocation->move(destinationPosOfPiece);
	}

	return returnString;
}


bool Side::isOneOfMyPiecesCanReachXLocation(const std::string location) const
{
	for (int i = 0; i < this->Pieces.size(); i++)
	{
		std::string oldPos = this->Pieces[i]->getPosition();

		if (this->Pieces[i]->isLegitMove(location))
		{
			return true;
		}
	}
	return false;
}


std::string Side::getKingLocation() const
{
	for (int i = 0; i < this->Pieces.size(); i++)
	{
		if (this->Pieces[i]->getType() == "King")
		{
			return this->Pieces[i]->getPosition();
		}
	}
}

void Side::setCheckState(const bool check)
{
	this->isChecked = check;
}

bool Side::isLegitEatingMoveForPawn(const std::string source, const std::string destination, const std::string name)
{
	bool diagonalOnce = false;

	//black can eat 1 diagonal forward which is backward for white
	if (name == "P")
	{
		diagonalOnce = source[1] - destination[1] == -1 && std::abs(source[0] - destination[0]) == 1;
	}
	else
	{
		diagonalOnce = source[1] - destination[1] == 1 && std::abs(source[0] - destination[0]) == 1;
	}

	return diagonalOnce;
}


