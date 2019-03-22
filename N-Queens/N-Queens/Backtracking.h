#pragma once

class Backtracking2 final {

public:

	explicit Backtracking2(int n = 4);

	~Backtracking2();

	void setBoard(int* board, int** domains);

	bool solveNQForwardCheckingWithDomainChecking(int y);

	void printBoard();

	void addThreats(int i, int j);

	void removeThreats(int i, int j);

	void updateDomains(int valMod, int row, int col);

	bool isQueenPlacementPossible(int col);
private:
	int n;
	int* board;
	int** domains;

};

class Backtracking final {

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