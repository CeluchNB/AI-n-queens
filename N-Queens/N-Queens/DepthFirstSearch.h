#pragma once

class DepthFirstSearch final{
public:
	DepthFirstSearch(int n = 8);
	DepthFirstSearch(const DepthFirstSearch&);
	DepthFirstSearch(DepthFirstSearch&&) noexcept;
	~DepthFirstSearch();
	DepthFirstSearch& operator=(const DepthFirstSearch& other) {
		n_ = other.n_;
		queenPlacements_ = new int[n_];
		for(auto i = 0; i < n_; ++i)
			queenPlacements_[i] = other.queenPlacements_[i];
		return *this;
	}
	DepthFirstSearch& operator=(DepthFirstSearch&& other) noexcept {
		n_ = other.n_;
		queenPlacements_ = other.queenPlacements_;
		other.queenPlacements_ = nullptr;
		return *this;
	}
	bool checkGoodPlace(int) const;
	void doSearch(int);
	void printBoard() const;
	void printSolutionCount() const;
private:
	int solutionCount_ = 0;
	int* queenPlacements_;
	int n_;
};
