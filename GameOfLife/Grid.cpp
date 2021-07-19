#include "Grid.hpp"
#include <iostream>
#include <map>

using namespace std;

//void Grid::setGridPattern(Pattern pattern)
//{
//	for (int i = 0; i < 9; i++)
//	{
//		for (int y = 0; y < 9; y++)
//		{
//			//squares_[i][y].getState() = pattern.getSquares()[i][y];
//			bool state = squares_[i][y].getState();
//			state = pattern.getSquares()[i][y];
//		}
//	}
//}

Grid::Grid(std::vector<std::vector<Square>> squares)
{
	squares_ = squares;
}

//void Grid::setGridSquares(Square squares[100][100])
//{
//	for (int i = 0; i < 100; i++)
//	{
//		for (int y = 0; y < 100; y++)
//		{
//			squares_[i][y].getState() = squares[i][y].getState();
//		}
//	}
//}

void Grid::setGridSquare(int row, int column, bool state)
{
	int num_of_rows = squares_.size();
	int num_of_columns = squares_[0].size();

	if (row < 0 || row >= num_of_rows)
	{
		cout << "Square position exceeds the row limit\n";
	}
	if (column < 0 || column >= num_of_columns)
	{
		cout << "Square position exceeds the column limit\n";
	}
	else if ((0 <= row and row < num_of_rows) && (0 <= column and column < num_of_columns))
	{
		squares_[row][column].getState() = state;
	}
}

void Grid::print()
{
	int num_of_rows = squares_.size();
	int num_of_columns = squares_[0].size();

	for (int i = 0; i < num_of_rows; i++)
	{
		for (int y = 0; y < num_of_columns; y++)
		{
			if (y != num_of_columns - 1)
				cout << squares_[i][y] << " | ";
			else
				cout << squares_[i][y];
		}
		if (i != num_of_rows - 1)
			cout << "\n- - - - - - - - - - - - - - - - - - -\n";
	}
}

unique_ptr<Grid> Grid::rememberState()
{
	return make_unique<Grid>(this->squares_);
}



int Grid::countNumLivingNeighborsCorner(char sign1, char sign2, char sign3, char sign4, int x, int y)
{
	int numLivingNeighbors = 0;

	if (initialState->squares_[x][operations[sign1](y, 1)].getState() == true)
		numLivingNeighbors++;
	if (initialState->squares_[operations[sign2](x, 1)][y].getState() == true)
		numLivingNeighbors++;
	if (initialState->squares_[operations[sign3](x, 1)][operations[sign4](y, 1)].getState() == true)
		numLivingNeighbors++;

	return numLivingNeighbors;
}

int Grid::numLivingNeighborsRow(char sign, int x, int y)
{
	int numLivingNeighbors = 0;

	if (initialState->squares_[x][y + 1].getState() == true)
		numLivingNeighbors++;
	if (initialState->squares_[x][y - 1].getState() == true)
		numLivingNeighbors++;
	if (initialState->squares_[operations[sign](x, 1)][y].getState() == true)
		numLivingNeighbors++;
	if (initialState->squares_[operations[sign](x, 1)][y - 1].getState() == true)
		numLivingNeighbors++;
	if (initialState->squares_[operations[sign](x, 1)][y + 1].getState() == true)
		numLivingNeighbors++;

	return numLivingNeighbors;
}

int Grid::numLivingNeighborsColumn(char sign, int x, int y) 
{
	int numLivingNeighbors = 0;

	if (initialState->squares_[x - 1][y].getState() == true)
		numLivingNeighbors++;
	if (initialState->squares_[x + 1][y].getState() == true)
		numLivingNeighbors++;
	if (initialState->squares_[x][operations[sign](y, 1)].getState() == true)
		numLivingNeighbors++;
	if (initialState->squares_[x + 1][operations[sign](y, 1)].getState() == true)
		numLivingNeighbors++;
	if (initialState->squares_[x - 1][operations[sign](y, 1)].getState() == true)
		numLivingNeighbors++;

	return numLivingNeighbors;
}

int Grid::numLivingNeighborsCorner(int x, int y)
{
	int num_of_rows = squares_.size() - 1;
	int num_of_columns = squares_[0].size() - 1;

	int numLivingNeighborsCorner = 0;

	if (x == 0 && y == 0) {
		numLivingNeighborsCorner += this->countNumLivingNeighborsCorner('+', '+', '+', '+', x, y);
		return numLivingNeighborsCorner;
	}

	if (x == 0 && y == num_of_columns) {
		numLivingNeighborsCorner += this->countNumLivingNeighborsCorner('-', '+', '+', '-', x, y);
		return numLivingNeighborsCorner;
	}

	if (x == num_of_rows && y == 0) {
		numLivingNeighborsCorner += this->countNumLivingNeighborsCorner('+', '-', '-', '+', x, y);
		return numLivingNeighborsCorner;
	}

	if (x == num_of_rows && y == num_of_columns) {
		numLivingNeighborsCorner += this->countNumLivingNeighborsCorner('-', '-', '-', '-', x, y);
		return numLivingNeighborsCorner;
	}

	return numLivingNeighborsCorner;
}

int Grid::numLivingNeighbors(int x, int y)
{
	int num_of_rows = squares_.size() - 1;
	int num_of_columns = squares_[0].size() - 1;

	int numLivingNeighbors = 0;

	// Checking if the square is one of the 4 corners
	if (x == 0 && y == 0) {
		numLivingNeighbors += this->numLivingNeighborsCorner(0, 0);
		return numLivingNeighbors;
	}

	if (x == 0 && y == num_of_columns) {
		numLivingNeighbors += this->numLivingNeighborsCorner(0, num_of_columns);
		return numLivingNeighbors;
	}

	if (x == num_of_rows && y == 0) {
		numLivingNeighbors += this->numLivingNeighborsCorner(num_of_rows, 0);
		return numLivingNeighbors;
	}

	if (x == num_of_rows && y == num_of_columns) {
		numLivingNeighbors += this->numLivingNeighborsCorner(num_of_rows, num_of_columns);
		return numLivingNeighbors;
	}

	// Checking if the square if one of the side row squares
	if (x == 0 && y != 0 && y != num_of_columns) {
		numLivingNeighbors += this->numLivingNeighborsRow('+', x, y);
		return numLivingNeighbors;
	}

	if (x == num_of_rows && y != 0 && y != num_of_columns) {
		numLivingNeighbors += this->numLivingNeighborsRow('-', x, y);
		return numLivingNeighbors;
	}

	// Checking if the square if one of the side column squares
	if (y == 0 && x != 0 && x != num_of_rows) {
		numLivingNeighbors += this->numLivingNeighborsColumn('+', x, y);
		return numLivingNeighbors;
	}

	if (y == num_of_columns && x != 0 && x != num_of_rows) {
		numLivingNeighbors += this->numLivingNeighborsColumn('-', x, y);
		return numLivingNeighbors;
	}

	// Check the living neighboring squares for any other squares
	else {
		if (initialState->squares_[x - 1][y].getState() == true)
			numLivingNeighbors++;
		if (initialState->squares_[x + 1][y].getState() == true)
			numLivingNeighbors++;
		if (initialState->squares_[x][y - 1].getState() == true)
			numLivingNeighbors++;
		if (initialState->squares_[x][y + 1].getState() == true)
			numLivingNeighbors++;
		if (initialState->squares_[x - 1][y - 1].getState() == true)
			numLivingNeighbors++;
		if (initialState->squares_[x - 1][y + 1].getState() == true)
			numLivingNeighbors++;
		if (initialState->squares_[x + 1][y - 1].getState() == true)
			numLivingNeighbors++;
		if (initialState->squares_[x + 1][y + 1].getState() == true)
			numLivingNeighbors++;
	}

	return numLivingNeighbors;
}

void Grid::update()
{
	int num_of_rows = squares_.size() - 1;
	int num_of_columns = squares_[0].size() - 1;

	int num_of_alive_squares = 0;

	//unique_ptr<Grid> mementoGrid = this->rememberState();
	initialState = this->rememberState();

	for (int i = 0; i < num_of_rows; i++)
	{
		for (int y = 0; y < num_of_columns; y++)
		{
			if (initialState->squares_[i][y].getState() == false)
			{
				if (this->numLivingNeighbors(i, y) == 3)
				{
					this->setGridSquare(i, y, true);
					continue;
				}
				else
					continue;
			}
			else
			{
				if (this->numLivingNeighbors(i, y) < 2 || this->numLivingNeighbors(i, y) > 3)
				{
					this->setGridSquare(i, y, false);
					continue;
				}
				else
					continue;
			}
		}
	}
}