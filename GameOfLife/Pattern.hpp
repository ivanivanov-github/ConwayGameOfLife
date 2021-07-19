#pragma once

#include "Square.hpp"

class Pattern
{
public:
	Pattern() = default;
	void setPattern(Square squares[9][9]);
	Square* getSquares();
private:
	Square squares_[9][9];
};
