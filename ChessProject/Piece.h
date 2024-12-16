#pragma once

#include <iostream>
#include <string>

#define WHITE 1
#define BLACK 0

class Piece
{

	Piece(std::string name, int color, std::string position);

	virtual ~Piece();

	//getters
	std::string getPosition()
	{
		return _position;
	}

	std::string getName()
	{
		return _name;
	}

	int getColor()
	{
		return _color;
	}







protected:

	std::string _position;
	int _color;
	std::string _name;

};
