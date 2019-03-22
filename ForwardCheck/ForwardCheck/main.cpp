// N-Queens.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include "ForwardCheck.h"
#include <ctime>
#include <chrono>
#include "pch.h"

int main()
{
	Backtracking b(23);
	Backtracking b2(23);

	int** test = new int*[4];
	test[0] = new int[4];
	test[1] = new int[4];
	test[2] = new int[4];
	test[3] = new int[4];


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			test[i][j] = 0;
		}
	}

	int** domain = new int*[4];
	domain[0] = new int[4];
	domain[1] = new int[4];
	domain[2] = new int[4];
	domain[3] = new int[4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			domain[i][j] = 0;
		}
	}

	domain[0][0] = 1;

	b.setBoard(test, domain);
	b.solveNQForwardChecking(0);
	b.printBoard();

	delete[] test[0];
	delete[] test[1];
	delete[] test[2];
	delete[] test[3];

	delete[] test;
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

