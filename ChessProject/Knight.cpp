#include "Knight.h"



Knight::Knight(const std::string name, const std::string type, const std::string position)
	: Piece(name, type, position)
{

}



bool Knight::isLegitMove(const std::string position)
{
	std::string currentPosition = getPosition();
	int left_right_move_squre = abs(currentPosition[0] - position[0]);
	int up_down_move_squre = abs(currentPosition[1] - position[1]);
	if ((left_right_move_squre == 2 && up_down_move_squre == 1) || (up_down_move_squre == 2 && left_right_move_squre == 1))
	{
		return true;
	}
	return false;
}

std::string Knight::move(const std::string newPosition)
{

	if (isLegitMove(newPosition))
	{
		setPosition(newPosition);
		return to_string(VALID_MOVE);
	}
	return std::to_string(INVALID_ILLEGAL_MOVE);
}


Knight::~Knight()
{
}


