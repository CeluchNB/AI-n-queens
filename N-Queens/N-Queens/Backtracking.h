#pragma once

class Backtracking {

public:

	Backtracking(int n = 8);

	~Backtracking();

	// function to check if space is safe for Queen
	bool isValidSpace(int i, int j);

	void setBoard(int** board);

	bool solveNQueens();

	void printBoard();
private:
	int n;
	int** board;

};