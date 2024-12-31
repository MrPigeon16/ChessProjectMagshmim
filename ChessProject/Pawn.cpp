#include "Pawn.h"

Pawn::Pawn(const std::string name, const std::string type, const std::string position)
	:Piece(name, type, position)
{
}


bool Pawn::isLegitMove(const string position)
{
	string currPosition = getPosition();
	bool straightOnce = false;

	//black can move 1 forward which is backward for white
	if (isItFirstMove())
	{
		if (this->getName() == "P")
		{
			straightOnce = ((currPosition[1] - position[1] == -2) || (currPosition[1] - position[1] == -1)) && (currPosition[0] - position[0] == 0);
		}
		else
		{
			straightOnce = (currPosition[1] - position[1] == 2) || (currPosition[1] - position[1] == 1) && (currPosition[0] - position[0] == 0);
		}

	}
	else
	{
		if (this->getName() == "P")
		{
			straightOnce = currPosition[1] - position[1] == -1 && (currPosition[0] - position[0] == 0);
		}
		else
		{
			straightOnce = currPosition[1] - position[1] == 1 && (currPosition[0] - position[0] == 0);
		}

	}

	return straightOnce;
}


bool Pawn::isLegitEatingMove(const string position)
{
	string currPosition = getPosition();

	bool diagonalOnce = false;

	//black can eat 1 diagonal forward which is backward for white
	if (getName() == "P")
	{
		diagonalOnce = currPosition[1] - position[1] == -1 && std::abs(currPosition[0] - position[0]) == 1;
	}
	else
	{
		diagonalOnce = currPosition[1] - position[1] == 1 && std::abs(currPosition[0] - position[0]) == 1;
	}

	return diagonalOnce;
}

string Pawn::move(const string newPosition)
{
	string returnString = to_string(INVALID_ILLEGAL_MOVE);
	if (isLegitMove(newPosition) || isLegitEatingMove(newPosition))
	{
		if (isItFirstMove())
		{
			changePawnMove(false);
		}
		setPosition(newPosition);
		returnString = to_string(VALID_MOVE);
	}

	return returnString;
}




Pawn::~Pawn()
{

}



