#pragma once

#include <iostream>
#include <string>
#define WHITE 1
#define BLACK 0

class Piece
{

	Piece(const std::string name, const std::string type, const std::string position, const int color );

	//getters
	std::string getPosition() const;
	std::string getName() const;
	std::string getType() const;
	int getColor() const;
	//setters
	void setPosition(const std::string newPosition);
	void setName(const std::string name);
	void setType(const std::string type);
	void setColor(const int color);


	//implement in the inhertiters
	//also destructors we need to implement only in the feature
	virtual std::string move(const std::string newPosition) = 0;
	virtual bool isLegitMove(const std::string position) = 0;

	





protected:

	std::string _position;
	std::string _name;
	std::string _type;
	int _color;


};
