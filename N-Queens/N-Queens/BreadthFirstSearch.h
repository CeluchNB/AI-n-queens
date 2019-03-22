#pragma once
#include <vector>
#include <queue>
#include <string>

struct Queen {
	int column = -1;
	int row = -1;

	Queen(const int row1, const int column1) {
		row = row1;
		column = column1;
	}

	bool isAttacking(const Queen&) const;
};

struct State {
	static unsigned size;
	std::vector<Queen> queens;

	static State fromString(const std::string&);
	std::string toString() const;

	bool isValidState() const;
	bool isEndState() const;
	std::vector<State> getSuccessors() const;
};

class BreadthFirstSearch final {
public:
	explicit BreadthFirstSearch(int n = 8);
	void step();
	State nextState();
	void run();
private:
	std::queue<State> states_;
	bool solutionFound_;
};

