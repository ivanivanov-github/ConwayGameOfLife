#include "Square.hpp"

Square::Square(bool alive)
{
	alive_ = alive;
}

bool& Square::getState()
{
	return alive_;
}

std::ostream& operator<<(std::ostream& os, const Square& square)
{
	os << square.alive_;
	return os;
}