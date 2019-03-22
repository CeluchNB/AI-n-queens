#include "stdafx.h"
#include <iostream>
#include "Backtracking.h"

Backtracking::Backtracking(int n) : n(n) {
	board = new int*[n];
	for (int i = 0; i < n; i++) {
		board[i] = new int[n];
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			board[x][y] = 0;
		}
	}
}

Backtracking::~Backtracking() {
	for (int i = 0; i < n; i++) {
		delete[] board[i];
	}
	delete[] board;
}

bool Backtracking::isValidSpace(int i, int j) {

	if (i >= n || j >= n) {
		return false;
	}

	for (int x = 0; x < n; x++) {
		if (board[i][x] == 1) {
			return false;
		}
	}

	for (int x = 0; x < n; x++) {
		if (board[x][j] == 1) {
			return false;
		}
	}

	int min1 = fmin(n - 1 - i, n - 1 - j);
	int x1 = i + min1;
	int y1 = j + min1;

	int min2 = fmin(n - 1 - i, j);
	int x2 = i + min2;
	int y2 = j - min2;

	for (x1; x1 >= 0; x1--) {
		if (y1 < 0) {
			break;
		}
		if (board[x1][y1] == 1) {
			return false;
		}
		y1--;
	}

	for (x2; x2 >= 0; x2--) {
		if (y2 >= n) {
			break;
		}
		if (board[x2][y2] == 1) {
			return false;
		}
		y2++;
	}
	return true;
}

void Backtracking::setBoard(int** board) {
	this->board = board;
}

bool Backtracking::solveNQueens(int y) {
	
	if (y == n) {
		printBoard();
		return true;
	}

	for (int i = 0; i < n; i++) {
		if (isValidSpace(i, y)) {
			board[i][y] = 1;

			if (solveNQueens(y + 1)) {
				return true;
			}
			else {
				board[i][y] = 0;
			}
		}
	}

	return false;
}

bool Backtracking::solveNQForwardChecking(int y) {

	if (y == n) {
		printBoard();
		return true;
	}

	for (int i = 0; i < n; i++) {
		if (isValidSpace(i,y)) {
			board[i][y] = 1;

			
			if (forwardCheck(y+1) && solveNQForwardChecking(y + 1)) {
				return true;
			}

			board[i][y] = 0;
		}
	}
	
	return false;
}

bool Backtracking::forwardCheck(int sq) {

	if (sq >= n) {
		return true;
	}

	bool hasSpace = false;
	for (int i = sq; i < n; i++) {
		hasSpace = false;
		for (int j = 0; j < n; j++) {
			if (isValidSpace(j, i)) {
				hasSpace = true;
				break;
			}
		}
		if (!hasSpace) {
			break;
		}
	}

	return hasSpace;
}

void Backtracking::printBoard() {
	std::cout << "{" << std::endl;;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << board[i][j] << " ";
		}

		std::cout << std::endl;
	}
	std::cout << "}" << std::endl;
}





Backtracking2::Backtracking2(int n) : n(n) {
	board = new int[n];
	

	for (int x = 0; x < n; x++) {
		board[x] = 0;
	}

	domains = new int*[n];
	for (int i = 0; i < n; i++) {
		domains[i] = new int[n];
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			domains[x][y] = 0;
		}
	}
}

Backtracking2::~Backtracking2() {
	delete[] board;

	for (int i = 0; i < n; i++) {
		delete[] domains[i];
	}
	delete[] domains;
}

void Backtracking2::setBoard(int* board, int** domains) {
	this->board = board;
	this->domains = domains;
}






void Backtracking2::printBoard() {
	std::cout << "board{" << std::endl;;
	for (int i = 0; i < n; i++) {
		std::cout << board[i] << " ";

		std::cout << std::endl;
	}
	std::cout << "}" << std::endl;

	std::cout << "domain{" << std::endl;;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << domains[i][j] << " ";
		}

		std::cout << std::endl;
	}
	std::cout << "}" << std::endl;
}

bool Backtracking2::solveNQForwardCheckingWithDomainChecking(int y) {

	if (y == n) {
		printBoard();
		return true;
	}

	for (int i = 0; i < n; i++) {
		if (domains[i][y] == 0) {
			board[y] = i;
			addThreats(i, y);
			printBoard();

			if (isQueenPlacementPossible(y)) {
				solveNQForwardCheckingWithDomainChecking(y + 1);
			}
			removeThreats(i, y);
		}
	}

	return false;
}


void Backtracking2::addThreats(int i, int j) {
	updateDomains(1, i, j);
}

void Backtracking2::removeThreats(int i, int j) {
	updateDomains(-1, i, j);
}

void Backtracking2::updateDomains(int valMod, int row, int col) {
	for (int i = 1; i < n - col; i++) {
		domains[row][col + i] += valMod;
		if (row + i < n) {
			domains[row + i][col + i] += valMod;
			domains[row + i][col] += valMod;

		}
		if (row - i >= 0) {
			domains[row - i][col + i] += valMod;
		}
	}
	domains[row][col] += 1;
	printBoard();
}

bool Backtracking2::isQueenPlacementPossible(int col) {
	for (int i = col + 1; i < n; i++) {
		bool canPlace = false;
		for (int row = 0; row < n && !canPlace; row++) {
			if (domains[row][i] == 0) {
				canPlace = true;
			}
		}
		if (!canPlace) {
			return false;
		}
	}
	return true;
}