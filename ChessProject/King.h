#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	// Constructor
	King(const std::string name, const std::string type, const std::string position);

	virtual std::string move(const std::string newPosition) override;
	virtual bool isLegitMove(const std::string position) override;


	// Destructor
	~King();

private:

};



