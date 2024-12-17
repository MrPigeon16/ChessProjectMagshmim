#include "Piece.h"
#include <iostream>

Piece::Piece(const std::string name, std::string type, const std::string position, const int color)
{
	this->_name = name;
	this->_position = position;
	this->_type = type;
	this->_color = color;
}

std::string Piece::getPosition() const
{
	return this->_position;
}

std::string Piece::getName() const
{
	return this->_name;
}

std::string Piece::getType() const
{
	return this->_type;
}

int Piece::getColor() const
{
	return this->_color;
}

void Piece::setName(const std::string name)
{
	_name = name;
}

void Piece::setType(const std::string type)
{
	this->_type = type;
}

void Piece::setColor(const int color)
{
	this->_color = color;
}

void Piece::setPosition(const std::string newPosition)
{
	this->_position = newPosition;
}








