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
	//bool isValid = true;

	if (i >= n || j >= n) {
		return false;
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			// check row
			if (x == i && board[x][y] == 1) {
				return false;
			}

			// check column
			if (y == j && board[x][y] == 1) {
				return false;
			}

			//if we are not on edge of board
			if (y > 0 && x > 0) {
				// check back left diagonal
				if (board[x - 1][y - 1] == 1 && (y-j == x-i)) {
					return false;
				}
			}

			//if we are not on edge of board
			if (x > 0 && y < n - 1) {
				// check back right diagonal
				if (board[x - 1][y + 1] == 1 && (x + y) == (i + j)) {
					return false;
				}
			}
		}
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