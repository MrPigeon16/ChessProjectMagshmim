#pragma once

#include <iostream>
#include <string>

#define WHITE 1
#define BLACK 0

class Piece
{

	Piece(const std::string name, const int color, const std::string position);

	//getters
	std::string getPosition() const;
	std::string getName() const;
	int getColor() const;
	//setters
	void setName(const std::string name);
	void setColor(const int color);
	void setPosition(const std::string newPosition);


	//implement in the inhertiters
	//also destructors we need to implement only in the feature
	virtual std::string move(const std::string newPosition) = 0;
	virtual bool isLegitMove(const std::string position) = 0;







protected:

	std::string _position;
	int _color;
	std::string _name;

};
