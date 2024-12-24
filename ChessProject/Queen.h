#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include <iostream>

class Queen : public Piece
{

	// Constructor
	Queen(const std::string name, const std::string type, const std::string position);

	virtual std::string move(const std::string newPosition) override;
	virtual bool isLegitMove(const std::string position) override;


	// Destructor
	~Queen();

};