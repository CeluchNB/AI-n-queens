// N-Queens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Backtracking.h"
#include <ctime>
#include <chrono>

int main()
{
	Backtracking b(28);
	//Backtracking b2(23);

	
	//b.solveNQForwardCheckingWithDomainChecking(0);
	b.solveNQForwardChecking(0);
	/*
	b.setBoard(test, domain);
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

	delete[] test;
	*/

	/*
	clock_t c3 = clock();
	if (b2.solveNQForwardChecking(0)) {
		clock_t c4 = clock();
		std::cout << "FC Backtracking Successful" << std::endl;
		double time = (double)(c4 - c3) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "Time: " << time << std::endl;
	}
	else {
		std::cout << "FC Backtracking Failed" << std::endl;
	}

	clock_t c1 = clock();
	if (b.solveNQueens(0)) {
		clock_t c2 = clock();
		std::cout << "Naive Backtracking Successful" << std::endl;
		double time = (double)(c2 - c1) / CLOCKS_PER_SEC * 1000.0;
		std::cout << "Time: " << time << std::endl;
	}
	else {
		std::cout << "Naive Backtracking Failed" << std::endl;
	}
	*/

    return 0;
}

