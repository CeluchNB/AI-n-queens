// N-Queens.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Backtracking.h"
#include "BreadthFirstSearch.h"
#include <chrono>

int main()
{
	Backtracking b(26);
	Backtracking b2(26);
	BreadthFirstSearch b3(9);
	system("pause");
	///*
	auto start = std::chrono::steady_clock::now();
	b3.run();
	auto end = std::chrono::steady_clock::now();
	std::cout << "BFS of size 9: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
	//*/
	system("pause");
	///*
	start = std::chrono::steady_clock::now();
	if (b.solveNQueens(0)) {
		std::cout << "Naive Backtracking Successful" << std::endl;
	}
	else {
		std::cout << "Naive Backtracking Failed" << std::endl;
	}
	end = std::chrono::steady_clock::now();
	std::cout << "Naive backtracking of size 26: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
	//*/
	system("pause");
	///*
	start = std::chrono::steady_clock::now();
	if (b2.solveNQForwardChecking(0)) {
		std::cout << "FC Backtracking Successful" << std::endl;
	}
	else {
		std::cout << "FC Backtracking Failed" << std::endl;
	}
	end = std::chrono::steady_clock::now();
	std::cout << "FC backtracking of size 26: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
	//*/
    return 0;
}

