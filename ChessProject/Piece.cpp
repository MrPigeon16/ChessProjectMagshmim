#include "Piece.h"
#include <iostream>

Piece::Piece(const std::string name, const int color, const std::string position)
{
	_name = name;
	_color = color;
	_position = position;
}

std::string Piece::getPosition() const
{
	return _position;
}

std::string Piece::getName() const
{
	return _name;
}

int Piece::getColor() const
{
	return _color;
}

void Piece::setName(const std::string name)
{
	_name = name;
}

void Piece::setColor(const int color)
{
	_color = color;
}

void Piece::setPosition(const std::string newPosition)
{
	_position = newPosition;
}








