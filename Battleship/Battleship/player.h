#pragma once
#include "board.h"
#include "ships.h"
#include "iterator.h"
#include <string>
#include <memory>

class Player
{
public:
	Player(const int& size = 10, const std::string name = " ") : player_board(size) { this->score = 0, this->sunken_ships = 0, _name = name; }
	void placeShips(void);
	bool replaceShip(const int&);
	bool rotateShip(const int&);
	bool attack(Player&);
	void save(std::ofstream&) const;
	void load(std::ifstream&);
	int getScore(void) const { return this->score; }
	bool isFinish(void) const { return sunken_ships == 6; }
	std::string getName(void) const { return this->_name; }
	~Player(void) { list_of_ships.clear(), _name.clear(); }
private:
	int fire(const std::pair<int, int>&);
	void show(Player&) const;
	std::pair<int, int> toBoardItem(const std::pair<char, int>&) const;
	Board player_board;
	std::vector<std::shared_ptr<Ship>> list_of_ships;
	int score, sunken_ships;
	std::string _name;
}; 

