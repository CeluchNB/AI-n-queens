#include <iostream>
#include "Backtracking.h"

Backtracking::Backtracking(const int n) : n(n) {
	board = new int*[n];
	for (auto i = 0; i < n; i++) {
		board[i] = new int[n];
	}

	for (auto x = 0; x < n; x++) {
		for (auto y = 0; y < n; y++) {
			board[x][y] = 0;
		}
	}
}

Backtracking::~Backtracking() {
	for (auto i = 0; i < n; i++) {
		delete[] board[i];
	}
	delete[] board;
}

bool Backtracking::isValidSpace(const int i, const int j) const {

	if (i >= n || j >= n) {
		return false;
	}

	for (auto x = 0; x < n; x++) {
		if (board[i][x] == 1) {
			return false;
		}
	}

	for (auto x = 0; x < n; x++) {
		if (board[x][j] == 1) {
			return false;
		}
	}

	const auto min1 = static_cast<int>(fmin(n - 1 - i, n - 1 - j));
	auto x1 = i + min1;
	auto y1 = j + min1;

	const auto min2 = static_cast<int>(fmin(n - 1 - i, j));
	auto x2 = i + min2;
	auto y2 = j - min2;

	for (; x1 >= 0; x1--) {
		if (y1 < 0) {
			break;
		}
		if (board[x1][y1] == 1) {
			return false;
		}
		y1--;
	}

	for (; x2 >= 0; x2--) {
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

bool Backtracking::solveNQueens(const int y) const {
	if (y == n) {
		printBoard();
		return true;
	}
	for (auto i = 0; i < n; i++) {
		if (isValidSpace(i, y)) {
			board[i][y] = 1;
			if (solveNQueens(y + 1)) return true;
			board[i][y] = 0;
		}
	}
	return false;
}

bool Backtracking::solveNQForwardChecking(const int y) const{

	if (y == n) {
		printBoard();
		return true;
	}

	auto validBoard = true;
	for (auto i = 0; i < n; i++) {
		if (isValidSpace(i, y)) {
			board[i][y] = 1;

			validBoard = forwardCheck(y + 1);

			if (validBoard && solveNQForwardChecking(y + 1)) {
				return true;
			}
			
			board[i][y] = 0;
		}
	}

	return false;
}

bool Backtracking::forwardCheck(const int sq) const {

	if (sq >= n) {
		return true;
	}

	auto hasSpace = false;
	for (auto i = sq; i < n; i++) {
		hasSpace = false;
		for (auto j = 0; j < n; j++) {
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

void Backtracking::printBoard() const {
	std::cout << "{" << std::endl;;
	for (auto i = 0; i < n; i++) {
		for (auto j = 0; j < n; j++) {
			std::cout << board[i][j] << " ";
		}

		std::cout << std::endl;
	}
	std::cout << "}" << std::endl;
}