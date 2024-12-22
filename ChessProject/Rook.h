#pragma once
#include "Piece.h"

class Rook: public Piece
{
public:
		// Constructor
		Rook(const std::string name, const std::string type, const std::string position);

		virtual std::string move(const std::string newPosition) override;
		virtual bool isLegitMove(const std::string position) override;

		
		// Destructor
		~Rook();

private:

};














