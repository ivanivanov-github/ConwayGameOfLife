#include "Pattern.hpp"

void Pattern::setPattern(Square squares[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		for (int y = 0; y < 9; y++)
		{
			squares_[i][y] = squares[i][y];
		}
	}
}


Square* Pattern::getSquares()
{
	return *squares_;
}