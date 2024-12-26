#include "Pawn.h"

Pawn::Pawn(const std::string name, const std::string type, const std::string position)
	:Piece(name, type, position)
{
}


bool Pawn::isLegitMove(const string position)
{
	std::string currentPosition = getPosition();
	int sumSquare = position[1] - currentPosition[1];
	if (sumSquare == 2 || sumSquare == 1)
	{
		return true;
	}
	return false;
}



string Pawn::move(const string newPosition)
{
	if (isLegitMove(newPosition))
	{
		setPosition(newPosition);
		return to_string(VALID_MOVE);
	}
	return to_string(INVALID_ILLEGAL_MOVE);
}




Pawn::~Pawn()
{

}



