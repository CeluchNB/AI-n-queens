// N-Queens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Backtracking.h"
#include <ctime>

int main()
{

	for (int i = 4; i < 24; i++) {
		Backtracking naive(i);
		Backtracking fc(i);

		clock_t nStart = clock();
		naive.solveNQueens(0);
		clock_t nEnd = clock();
		std::cout << "Naive Time (" << i << "): " << (double)(nEnd - nStart) / CLOCKS_PER_SEC * 1000.0 << std::endl;

		clock_t fcStart = clock();
		fc.solveNQForwardChecking(0);
		clock_t fcEnd = clock();
		std::cout << "FC Time (" << i << "): " << (double)(fcEnd - fcStart) / CLOCKS_PER_SEC * 1000.0 << std::endl;
	}

    return 0;
}

