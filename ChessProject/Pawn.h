#pragma once
#include "Piece.h"
class Pawn : public Piece
{
public:	
	// Constructor
	Pawn(const std::string name, const std::string type, const std::string position);

	virtual std::string move(const std::string newPosition) override;
	virtual bool isLegitMove(const std::string position) override;

	bool isLegitEatingMove(const string position);

	// Destructor
	~Pawn();



};







