#include "Grid.hpp"
#include "Square.hpp"
#include "Pattern.hpp"

#include <iostream>
using namespace std;

int main(){
	Grid grid;
	grid.setGridSquare(2, 3, true);
	grid.setGridSquare(3, 4, true);
	grid.setGridSquare(4, 4, true);
	grid.setGridSquare(4, 3, true);
	grid.setGridSquare(4, 2, true);
	grid.print();
	cout << "\n\n\n\n\n";
	grid.update();
	grid.print();
	cout << "\n\n\n\n\n";
	grid.update();
	grid.print();
	cout << "\n\n\n\n\n";
	grid.update();
	grid.print();
	cout << "\n\n\n\n\n";
	grid.update();
	grid.print();
	cout << "\n\n\n\n\n";
}