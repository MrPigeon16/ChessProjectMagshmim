#pragma once

#include <iostream>
#include <string>
#define WHITE 1
#define BLACK 0

enum GameMoves
{
	VALID_MOVE = 0,
	VALID_MOVE_CAUSED_CHECK = 1,
	INVALID_NO_PIECE_AT_SOURCE = 2,
	INVALID_DEST_OCCUPIED = 3,
	INVALID_CAUSES_SELF_CHECK = 4,
	INVALID_INDEX_OUT_OF_BOUNDS = 5,
	INVALID_ILLEGAL_MOVE = 6,
	INVALID_SOURCE_EQUALS_DEST = 7,
	VALID_CHECKMATE = 8
};



class Piece
{
public:
	// Constructor
	Piece(const std::string name, const std::string type, const std::string position);
	
	// Destructor
	virtual ~Piece();

	//getters
	std::string getPosition() const;
	std::string getName() const;
	std::string getType() const;
	
	//setters
	void setPosition(const std::string newPosition);
	void setName(const std::string name);
	void setType(const std::string type);


	//implement in the inhertiters
	//also destructors we need to implement only in the feature
	virtual std::string move(const std::string newPosition) = 0;
	virtual bool isLegitMove(const std::string position) = 0;
	////////////////////////////////////////
	void changePawnMove(const bool newState);
	bool isItFirstMove() const;




	





private:

	std::string _position;
	std::string _name;
	std::string _type;

	bool isItFirstPawnMove;


};
