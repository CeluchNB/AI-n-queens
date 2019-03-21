#pragma once

class Backtracking final{

public:

	explicit Backtracking(int n = 8);

	~Backtracking();

	// function to check if space is safe for Queen
	bool isValidSpace(int i, int j) const;

	void setBoard(int** board);

	bool solveNQueens(int y) const;

	bool solveNQForwardChecking(int y) const;

	bool forwardCheck(int sq) const;

	void printBoard() const;
private:
	int n;
	int** board;
};