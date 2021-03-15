#include "battleship.h"

std::shared_ptr<BattleShip> BattleShip::instance = nullptr;

std::shared_ptr<BattleShip> BattleShip::getGame(void)
{
	if (instance == nullptr)
	{
		BattleShip* p = new BattleShip;
		instance = std::make_shared<BattleShip>(*p);
		delete p;
	}
	return instance;
}

void BattleShip::help(void) const
{
	system("cls");
	std::cout << "Welcome to the help section !\n";
	std::cout << "Useful information:\n";
	std::cout << "a)new game          ->  generates a new game\n";
	std::cout << "b)interactive game  ->  in which players place their ships, and then they strike alternately\n";
	std::cout << "c)sequential game   ->  in which alternately, one player places his ships and the other tries to it sinks them.\n";
	std::cout << "d)save              ->  saves the current game configuration\n";
	std::cout << "e)load              ->  load the last saved configuration\n";
	std::cout << "f)simple rules:\n";
	std::cout << "    -each player places the 6 ships on the board\n";
	std::cout << "    -a ship is sunk when all the squares that make it up are hit\n";
	std::cout << "    -for each correct shot, the player receives 100 points\n";
	std::cout << "    -for each incorrect shot, the player loses 50 points\n";
	std::cout << "    -the game ends when all ships of both players are shot down\n";
	std::cout << "    -the player with the highest score wins\n";
	std::cout << "\nFor more information, contact the email address 'smarandache.alexandru.q5n@student.ucv.ro'\n";
	std::cout << "Have fun !\n";
	system("pause");
}

void BattleShip::menu(void)
{
	char option;
	std::unique_ptr<Game> newGame;
	system("cls");
	while (true)
	{
		std::cout << "1/ New game.\n";
		std::cout << "2/ Load an old game.\n";
		std::cout << "3/ Help.\n";
		std::cout << "4/ Turn off.\n";
		std::cout << "Enter the desired option: "; std::cin >> option;
		switch (option)
		{
		case '1':
		{
			system("cls");
			char op = 'a';
			std::cout << "1/ Interactive game.\n";
			std::cout << "2/ Sequential game.\n";
			std::cout << "Enter the desired option: "; std::cin >> op;
			while (op != '1' && op != '2')
			{
				std::cout << "\nIncorrect. Please, retry.\n";
				std::cout << "Enter the desired option: "; std::cin >> op;
			}
			if (op == '1')
			{
				newGame = std::make_unique<InteractiveGame>();
			}
			else
			{
				newGame = std::make_unique<SequentialGame>();
			}
			newGame->menu();
			return;
			break;
		}
		case '2':
		{
			load();
			return;
		}
		case '3':
		{
			help();
			break;
		}
		case '4':
		{
			std::cout << "Have a nice day !\n";
			return;
		}
		default:
			break;
		}
		system("cls");
	}
}

void BattleShip::load(void)
{
	std::ifstream f("info.txt");
	std::unique_ptr<Game> oldGame;
	char op;
	f >> op;
	if (op == 's')
	{
		oldGame = std::make_unique<SequentialGame>(true);
	}
	else
	{
		oldGame = std::make_unique<InteractiveGame>(true);
	}
	oldGame->load(f);
	f.close();
}