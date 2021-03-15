#include "game.h"

Game::Game(void)
{
	player1 = nullptr;
	player2 = nullptr;
}

void Game::save(void) const
{
	std::ofstream g("info.txt");
	player1->save(g);
	player2->save(g);
}

void Game::load(std::ifstream& f)
{
	player1->load(f);
	player2->load(f);
	menu(true);
}

void Game::menuPlayer(std::unique_ptr<Player>& _player)
{
	bool ok = false;
	while (true)
	{
		char option;
		system("cls");
		std::cout << "1/ Place the ships.\n";
		std::cout << "2/ Replace ship.\n";
		std::cout << "3/ Rotate the ships.\n";
		std::cout << "4/ Play.\n";
		std::cin >> option;
		switch (option)
		{
		case '1':
		{
			if (!ok)
			{
				_player->placeShips();
				ok = true;
			}
			else
			{
				std::cout << "The ships are already placed.\n";
			}
			break;
		}
		case '2':
		{
			int index;
			std::cout << "The index of the ship to be replaced: "; std::cin >> index;
			while (index < 1 || index > 6)
			{
				std::cout << "Incorrect index. Please retry. \n New index: "; std::cin >> index;
			}
			_player->replaceShip(--index);
			break;
		}
		case '3':
		{
			int index;
			std::cout << "The index of the ship to be rotated: "; std::cin >> index;
			while (index < 1 || index > 6)
			{
				std::cout << "Incorrect index. Please retry. \n New index: "; std::cin >> index;
			}
			if (!_player->rotateShip(--index))
			{
				std::cout << "The ship cannot rotate.\n";
				system("pause");
			}
			break;
		}
		case '4':
		{
			if (ok)
			{
				return;
			}
			else
			{
				std::cout << "You must enter the ships to start the game.\n";
				system("pause");
				break;
			}
		}
		default:
		{
			std::cout << "Incorrect option.\n";
			system("pause");
			break;
		}
		}
	}
}

bool Game::player1Attack(void)
{
	return this->player1->attack(*player2);
}

bool Game::player2Attack(void)
{
	return this->player2->attack(*player1);
}

InteractiveGame::InteractiveGame(void)
{
	system("cls"); 
	std::cout << "Welcome to interactive game !\n\n";
	std::string name;
	int size;
	std::cout << "Number of row/column items: "; std::cin >> size;
	std::cout << "Name of player 1: "; std::cin >> name;
	player1 = std::make_unique<Player>(size, name);
	std::cout << "Name of player 2: "; std::cin >> name;
	player2 = std::make_unique<Player>(size, name);
}

InteractiveGame::InteractiveGame(bool temp)
{
	player1 = std::make_unique<Player>(10, "");
	player2 = std::make_unique<Player>(10, "");
}

void InteractiveGame::save(void) const
{
	std::ofstream g("info.txt");
	g << "i\n";
	player1->save(g);
	player2->save(g);
}

void InteractiveGame::menu(bool ok)
{
	system("cls");
	if (!ok)
	{
		std::cout << player1->getName() << " will place the ships.\n";
		system("pause");
		menuPlayer(player1);
		system("cls");
		std::cout << player2->getName() << " will place the ships.\n";
		system("pause");
		menuPlayer(player2);
		system("cls");
	}
	
	bool p1_out = false, p2_out = false;
	if (ok)
	{
		p1_out = player2->isFinish();
		p2_out = player1->isFinish();
	}
	while (!p1_out && !p2_out)
	{
		if (!p1_out)
		{
			p1_out = player2Attack();
		}
		if (!p2_out)
		{
			p2_out = player1Attack();
		}
		char option;
		std::cout << "Choose the desired option:\n";
		std::cout << "1/ Save and quit.\n";
		std::cout << "2/ Quit.\n";
		std::cout << "Another key/ Continue.\n";
		std::cin >> option;
		switch (option)
		{
		case '1':
		{
			save();
			return;
		}
		case '2':
		{
			return;
		}
		default:
			break;
		}
		system("cls");
	}
	system("cls");
	std::cout << player1->getName() << " has the score " << player1->getScore() << std::endl;
	std::cout << player2->getName() << " has the score " << player2->getScore() << std::endl << std::endl;
	if (player1->getScore() > player2->getScore())
	{
		std::cout << player1->getName() << " won.\n";
	}
	else if (player1->getScore() < player2->getScore())
	{
		std::cout << player2->getName() << " won.\n";
	}
	else
	{
		std::cout << "Draw\n";
	}
}

SequentialGame::SequentialGame(void)
{
	system("cls");
	std::cout << "Welcome to sequential game !\n\n";
	std::string name;
	int size;
	std::cout << "Number of row/column items: "; std::cin >> size;
	std::cout << "Name of player 1: "; std::cin >> name;
	player1 = std::make_unique<Player>(size, name);
	std::cout << "Name of player 2: "; std::cin >> name;
	player2 = std::make_unique<Player>(size, name);
}

SequentialGame::SequentialGame(bool temp)
{
	player1 = std::make_unique<Player>(10, "");
	player2 = std::make_unique<Player>(10, "");
}

void SequentialGame::save(void) const
{
	std::ofstream g("info.txt");
	g << "s\n";
	player1->save(g);
	player2->save(g);
}

void SequentialGame::menu(bool ok)
{
	system("cls");
	if (!ok)
	{
		std::cout << player1->getName() << " will place the ships.\n";
		system("pause");
		menuPlayer(player1);
	}
	bool out = false;
	bool temp = false;
	if (ok)
	{
		out = player2->isFinish();
		temp = out;
	}
	while (!out)
	{
		out = player2Attack();
		char option;
		std::cout << "Choose the desired option:\n";
		std::cout << "1/ Save and quit.\n";
		std::cout << "2/ Quit.\n";
		std::cout << "Another key/ Continue.\n";
		std::cin >> option;
		switch (option)
		{
		case '1':
		{
			save();
			return;
		}
		case '2':
		{
			return;
		}
		default:
			break;
		}
		system("cls");
	}
	if (!temp)
	{
		std::cout << player1->getName() << " has all the ships sunk.\n";
		system("pause");
		system("cls");
		std::cout << player2->getName() << " will place the ships.\n";
		system("pause");
		menuPlayer(player2);
	}
	out = false;
	while (!out)
	{
		out = player1Attack();
		char option;
		std::cout << "Choose the desired option:\n";
		std::cout << "1/ Save and quit.\n";
		std::cout << "2/ Quit.\n";
		std::cout << "Another key/ Continue.\n";
		std::cin >> option;
		switch (option)
		{
		case '1':
		{
			save();
			return;
		}
		case '2':
		{
			return;
		}
		default:
			break;
		}
		system("cls");
	}
	std::cout << player2->getName() << " has all the ships sunk.\n";
	system("pause");
	system("cls");
	std::cout << player1->getName() << " has the score " << player1->getScore() << std::endl;
	std::cout << player2->getName() << " has the score " << player2->getScore() << std::endl << std::endl;
	if (player1->getScore() > player2->getScore())
	{
		std::cout << player1->getName() << " won.\n";
	}
	else if (player1->getScore() < player2->getScore())
	{
		std::cout << player2->getName() << " won.\n";
	}
	else
	{
		std::cout << "Draw\n";
	}
}
