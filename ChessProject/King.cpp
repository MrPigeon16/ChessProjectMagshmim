#include "King.h"
#include "Piece.h"
#include <string>

King::King(const std::string name, const std::string type, const std::string position) : Piece(name, type, position) 
{
}

bool King::isLegitMove(const std::string position)
{
	std::string currentPosition = getPosition();

	bool diagonalOnce = std::abs(currentPosition[1] - position[1]) == 1 && std::abs(currentPosition[0] - position[0]) == 1;
	bool straightOnce = (std::abs(currentPosition[0] - position[0]) == 1 && std::abs(currentPosition[1] - position[1]) == 0) || (std::abs(currentPosition[0] - position[0]) == 0 && std::abs(currentPosition[1] - position[1]) == 1);

	if (straightOnce || diagonalOnce)
	{
		return true;
	}

	return false;
}

King::~King()
{
}

std::string King::move(const std::string newPosition)
{
	std::string returnString = std::to_string(INVALID_ILLEGAL_MOVE);

	if (isLegitMove(newPosition))
	{
		setPosition(newPosition);
		returnString = std::to_string(VALID_MOVE);
	}

	return returnString;

}