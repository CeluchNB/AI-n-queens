#include "DepthFirstSearch.h"
#include <cstdlib>
#include <iostream>

DepthFirstSearch::DepthFirstSearch(const int n) : n_(n) {
	if (n < 1) {
		std::cerr << "Error: n must be greater than 0" << std::endl;
		exit(EXIT_FAILURE);
	}
	queenPlacements_ = new int[n * n];
	for(auto i = 0; i < n * n; ++i)
		queenPlacements_[i] = 0;
}

DepthFirstSearch::DepthFirstSearch(const DepthFirstSearch& other) {
	n_ = other.n_;
	queenPlacements_ = new int[n_];
	for(auto i = 0; i < n_; ++i) 
		queenPlacements_[i] = other.queenPlacements_[i];
}

DepthFirstSearch::DepthFirstSearch(DepthFirstSearch&& other) noexcept {
	n_ = other.n_;
	queenPlacements_ = other.queenPlacements_;
	other.queenPlacements_ = nullptr;
}

DepthFirstSearch::~DepthFirstSearch() {
	delete[] queenPlacements_;
}

bool DepthFirstSearch::checkGoodPlace(const int n) const {
	for(auto i = 0; i < n; ++i) {
		if (queenPlacements_[i] == queenPlacements_[n]) return false;
		if (queenPlacements_[i] - queenPlacements_[n] == n - i) return false;
		if (queenPlacements_[n] - queenPlacements_[i] == n - i) return false;
	}
	return true;
}

void DepthFirstSearch::doSearch(const int k) {
	if (k == n_) {
		++solutionCount_;
	}
	else {
		for(auto i = 0; i < n_; ++i) {
			queenPlacements_[k] = i;
			if (checkGoodPlace(k)) doSearch(k + 1);
		}
	}
}

void DepthFirstSearch::printBoard() const {
	for(auto i = 0; i < n_; ++i) {
		for(auto j = 0; j < n_; ++j) {
			if (queenPlacements_[i] == j) std::cout << "1 ";
			else std::cout << "0 ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void DepthFirstSearch::printSolutionCount() const {
	std::cout << solutionCount_ << std::endl;
}