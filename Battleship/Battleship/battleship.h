#pragma once
#include "game.h"

class BattleShip
{
public:
	static std::shared_ptr<BattleShip> getGame(void);
	void menu(void);
protected: 
	BattleShip(void) {  }
private:
	static std::shared_ptr<BattleShip> instance;
	void load(void);
	void help(void) const;
};

