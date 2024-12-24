#include "Queen.h"


Queen::Queen(const std::string name, const std::string type, const std::string position)
	:Piece(name, type, position)
{

}

bool Queen::isLegitMove(const std::string position)
{

	std::string currentPosition = getPosition();
	int count_Diagonal_moves = abs(currentPosition[0] - position[0]);
	int count_Stright_moves = abs(currentPosition[1] - position[1]);
		//rook moves																//Bishop moves
	if ((currentPosition[0] != position[0] && currentPosition[1] != position[1]) || (count_Diagonal_moves != count_Stright_moves))
	{
		return false;
	}

	return true;
}


std::string Queen::move(const std::string newPosition)
{

	if (isLegitMove(newPosition))
	{
		setPosition(newPosition);
		return to_string(VALID_MOVE);
	}
	return to_string(INVALID_ILLEGAL_MOVE);


}



Queen::~Queen()
{
}


















