#pragma once
#include "Piece.h"
using namespace std;


class Bishop : public Piece
{
public:
	//Consttructor
	Bishop(const std::string name, const std::string type, const std::string position);

	virtual bool isLegitMove(const std::string position) override;
	virtual std::string move(const std::string newPosition) override;

	//Destructor
	~Bishop();
};