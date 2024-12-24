#include "Bishop.h"




Bishop::Bishop(const string name, const string type, const string position) : Piece(name, type, position)
{
}
//D4 C5
// A - 
// poistion[0] -  letter , Postion[1] - number

/*
Function will check of both of the poestion have chnage
input: postion - the new postion the user want to move to
ouput: return true if good new postion, false if not
*/
bool Bishop::isLegitMove(const std::string position)
{
    //The user have to move the sqaures in both to move diagonaly

    std::string currentPostion = getPosition();
    int count_Diagonal_moves = abs(currentPostion[0] - position[0]);
    int count_Stright_moves = abs(currentPostion[1] - position[1]);
    if (count_Diagonal_moves == count_Stright_moves)
    {
        return true;
    }

    return false;
}

std::string Bishop::move(const std::string newPosition)
{

    if (isLegitMove(newPosition))
    {
        setPosition(newPosition);
        return to_string(VALID_MOVE);
    }
    return to_string(INVALID_ILLEGAL_MOVE);
}

Bishop::~Bishop()
{
}
