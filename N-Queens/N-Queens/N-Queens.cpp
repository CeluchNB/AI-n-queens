// N-Queens.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Backtracking.h"
#include "BreadthFirstSearch.h"
#include <chrono>

int main()
{
	//Backtracking b(25);
	//Backtracking b2(25);
	BreadthFirstSearch b3(9);
	system("pause");
	const auto start = std::chrono::steady_clock::now();
	b3.run();
	const auto end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
	/*int** test = new int*[4];
	test[0] = new int[4];
	test[1] = new int[4];
	test[2] = new int[4];
	test[3] = new int[4];


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			test[i][j] = 0;
		}
	}

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
	b.printBoard();

	delete[] test[0];
	delete[] test[1];
	delete[] test[2];
	delete[] test[3];

	delete[] test;*/
	/*
	if (b.solveNQueens(0)) {
		std::cout << "Naive Backtracking Successful" << std::endl;
	}
	else {
		std::cout << "Naive Backtracking Failed" << std::endl;
	}

	if (b2.solveNQForwardChecking(0)) {
		std::cout << "FC Backtracking Successful" << std::endl;
	}
	else {
		std::cout << "FC Backtracking Failed" << std::endl;
	}
	*/
    return 0;
}

