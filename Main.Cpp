#include <iostream>
#include <fstream>
#include "Fraction.hpp"

int main() {
	Fraction F1;

	int x = 9;
	int y = 11;

	F1.setNumDen(x, y);
	Fraction F2 = F1;

	std::cout << "cool beans";
}
