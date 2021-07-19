#pragma once

#include <vector>
#include <memory>
#include <map>
#include <functional>
#include "Square.hpp"
#include "Pattern.hpp"

class Grid
{
public:
	Grid() = default;
	Grid(std::vector<std::vector<Square>> squares);
	//void setGridPattern(Pattern pattern);
	void setGridSquare(int row, int column, bool state);
	//void setGridSquares(Square squares[100][100]);
	void print();
	void update();
	std::unique_ptr<Grid> rememberState();
	int numLivingNeighbors(int x, int y);
	int numLivingNeighborsCorner(int x, int y);
	int countNumLivingNeighborsCorner(char sign1, char sign2, char sign3, char sign4, int x, int y);
	int numLivingNeighborsRow(char sign, int x, int y);
	int numLivingNeighborsColumn(char sign, int x, int y);

private:
	std::vector<std::vector<Square>> squares_{ { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
											   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
											   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
											   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
											   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
											   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
											   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
											   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
											   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
											   { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
											 };

	std::unique_ptr<Grid> initialState;
	
	std::map< char, std::function<double(double, double)> > operations = {
		{'+', [](double a, double b) { return a + b; } },
		{'-', [](double a, double b) { return a - b; } }
	};
};

