#pragma once
#include <iostream>
#include <fstream>
#include <vector> 

class Board
{
public:
	Board(const int& = 10);
	~Board(void);
	int& getPoint(const std::pair<int, int>&);
	unsigned int getSize(void) const;
	void show(const char&) const;
	void display(const char&) const;
	bool valid(const std::pair<int, int>&) const;
	void save(std::ofstream&) const;
	void load(std::ifstream&);
private:
	std::vector<std::vector<int>> _table;
};