#include "BreadthFirstSearch.h"
#include <sstream>
#include <iostream>

bool Queen::isAttacking(const Queen& other) const {
	if (row == other.row || column == other.column) return true;
	return abs(row - other.row) == abs(column - other.column);
}

unsigned State::size = 8;

State State::fromString(const std::string& string) {
	State state;
	std::stringstream ss(string);
	std::string token;
	auto i = 0;
	while(std::getline(ss, token, ',')) {
		state.queens.emplace_back(atoi(token.c_str()), i);
		++i;
	}
	return state;
}

std::string State::toString() const {
	std::stringstream ss;
	for(const auto queen : queens) {
		ss << queen.row << ",";
	}
	auto ret = ss.str();
	return ret.substr(0, ret.length() - 1);
}

bool State::isValidState() const {
	for(auto i = 0U; i < queens.size(); ++i)
		for(auto j = i + 1; j < queens.size(); ++j)
			if (queens[i].isAttacking(queens[j])) return false;
	return true;
}

bool State::isEndState() const {
	return isValidState() && queens.size() == size;
}

std::vector<State> State::getSuccessors() const {
	std::vector<State> ret;
	for(auto i = 0U; i < size; ++i) {
		auto string = toString();	
		std::stringstream ss;
		ss << string;
		if (string.length() == 0) {
			ss << i;
		}
		else {
			ss << "," << i;
		}
		auto s = fromString(ss.str());
		if (s.isValidState()) ret.push_back(s);
	}
	return ret;
}


BreadthFirstSearch::BreadthFirstSearch(const int n) {
	State::size = n;
	solutionFound_ = false;
	states_.emplace();
}

void BreadthFirstSearch::step() {
	if (states_.empty()) return;
	auto current = nextState();
	if(current.isEndState()) {
		solutionFound_ = true;
		std::cout << "Solution found: " << current.toString() << std::endl;
		return;
	}
	for(auto state : current.getSuccessors()) {
		states_.push(state);
	}
}

State BreadthFirstSearch::nextState() {
	auto s = states_.front();
	states_.pop();
	return s;
}

void BreadthFirstSearch::run() {
	while (!states_.empty() && !solutionFound_) {
		step();
	}
}
