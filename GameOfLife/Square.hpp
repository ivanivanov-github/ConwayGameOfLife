#pragma once

#include <iostream>

class Square
{
public:
	Square() = default;
	Square(bool alive);
	bool& getState();

	bool operator[](int index) { return alive_; };
	friend std::ostream& operator<<(std::ostream& os, const Square& square);
private:
	bool alive_ = false;
};
