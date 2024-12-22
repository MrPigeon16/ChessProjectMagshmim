#pragma once
#include "Piece.h"

class Knight : public Piece
{
	Knight(const std::string name, const std::string type, const std::string position);
	~Knight();

	virtual bool isLegitMove(const std::string position) override;
	virtual std::string move(const std::string newPosition) override;


};