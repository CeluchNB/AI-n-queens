#pragma once

class Backtracking2 {

public:

	Backtracking2(int n = 4);

	~Backtracking2();


	void setBoard(int* board, int** domains);

	bool solveNQForwardCheckingWithDomainChecking(int y);

	void printBoard();

	void addThreats(int i, int j);

	void removeThreats(int i, int j);

	void updateDomains(int valMod, int i, int j);

	bool isQueenPlacementPossible(int col);
private:
	int n;
	int* board;
	int** domains;

};

class Backtracking {

public:

	Backtracking(int n = 8);

	~Backtracking();

	// function to check if space is safe for Queen
	bool isValidSpace(int i, int j);

	void setBoard(int** board);

	bool solveNQueens(int y);

	bool solveNQForwardChecking(int y);

	bool forwardCheck(int sq);

	void printBoard();
private:
	int n;
	int** board;
};