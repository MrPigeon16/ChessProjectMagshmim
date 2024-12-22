#include "Rook.h"
#include "Piece.h"
#include <string>

Rook::Rook(const std::string name, const std::string type, const std::string position) : Piece(name, type, position)
{
}

std::string Rook::move(const std::string newPosition)
{
	std::string returnString = std::to_string(INVALID_ILLEGAL_MOVE);

	if (isLegitMove(newPosition))
	{
		setPosition(newPosition);
		returnString = std::to_string(VALID_MOVE);
	}

	return returnString;
}

bool Rook::isLegitMove(const std::string position)
{
	std::string currentPosition = getPosition();

	if (currentPosition[0] != position[0] && currentPosition[1] != position[1])
	{
		return false;
	}

	return true;

}

Rook::~Rook()
{

}
