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