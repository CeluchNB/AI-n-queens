// N-Queens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Backtracking.h"

int main()
{
	Backtracking b(4);

	int** test = new int*[4];
	test[0] = new int[4];
	test[1] = new int[4];
	test[2] = new int[4];
	test[3] = new int[4];

	test[0][0] = 1;

	b.setBoard(test);
	std::cout << b.isValidSpace(0, 0) << std::endl;
	std::cout << b.isValidSpace(1, 0) << std::endl;
	std::cout << b.isValidSpace(0, 1) << std::endl;
	std::cout << b.isValidSpace(1, 1) << std::endl;
	std::cout << b.isValidSpace(0, 2) << std::endl;
	std::cout << b.isValidSpace(0, 3) << std::endl;
	std::cout << "Expect true: " << b.isValidSpace(1, 2) << std::endl;
	std::cout << "Expect true: " << b.isValidSpace(1, 3) << std::endl;
	std::cout << b.isValidSpace(2, 0) << std::endl;
	std::cout << "Expect true: " << b.isValidSpace(2, 1) << std::endl;
	std::cout << b.isValidSpace(2, 2) << std::endl;
	std::cout << "Expect true: " << b.isValidSpace(2, 3) << std::endl;
	std::cout << b.isValidSpace(3, 0) << std::endl;
	std::cout << "Expect true: " << b.isValidSpace(3, 1) << std::endl;
	std::cout << "Expect true: " << b.isValidSpace(3, 2) << std::endl;
	std::cout << b.isValidSpace(3, 3) << std::endl;
	std::cout << b.isValidSpace(5, 5) << std::endl;

	delete[] test[0];
	delete[] test[1];
	delete[] test[2];
	delete[] test[3];

	delete[] test;

    return 0;
}

