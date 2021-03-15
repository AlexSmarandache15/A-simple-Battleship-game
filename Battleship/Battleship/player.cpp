#include "player.h"

void Player::placeShips(void)
{
	std::pair<int, int> points[2];
	std::pair<char, int> _points[2];
	system("cls");
	player_board.display(toupper(_name[0]));
	list_of_ships.push_back(std::shared_ptr<Ship1>(new Ship1));
	std::cout << "Place first ship: ";
	std::cout << "Size: " << list_of_ships[0]->getSize() << std::endl;
	std::cout << "Start point: "; std::cin >> _points[0].first >> _points[0].second;
	std::cout << "End point: "; std::cin >> _points[1].first >> _points[1].second;
	points[0] = toBoardItem(_points[0]);
	points[1] = toBoardItem(_points[1]);
	while (!list_of_ships[0]->placeShip(points[0], points[1], this->player_board))
	{
		system("cls");
		player_board.display(toupper(_name[0]));
		std::cout << "Incorrect placement. Retry\n";
		std::cout << "Place first ship: ";
		std::cout << "Size: " << list_of_ships[0]->getSize() << std::endl;
		std::cout << "Start point: "; std::cin >> _points[0].first >> _points[0].second;
		std::cout << "End point: "; std::cin >> _points[1].first >> _points[1].second;
		points[0] = toBoardItem(_points[0]);
		points[1] = toBoardItem(_points[1]);
	}
	
	system("cls");
	player_board.display(toupper(_name[0]));
	list_of_ships.push_back(std::shared_ptr<Ship2>(new Ship2));
	std::cout << "Place scond ship: ";
	std::cout << "Size: " << list_of_ships[1]->getSize() << std::endl;
	std::cout << "Start point: "; std::cin >> _points[0].first >> _points[0].second;
	std::cout << "End point: "; std::cin >> _points[1].first >> _points[1].second;
	points[0] = toBoardItem(_points[0]);
	points[1] = toBoardItem(_points[1]);
	while (!list_of_ships[1]->placeShip(points[0], points[1], this->player_board))
	{
		system("cls");
		player_board.display(toupper(_name[0]));
		std::cout << "Incorrect placement. Retry\n";
		std::cout << "Place seond ship: ";
		std::cout << "Size: " << list_of_ships[1]->getSize() << std::endl;
		std::cout << "Start point: "; std::cin >> _points[0].first >> _points[0].second;
		std::cout << "End point: "; std::cin >> _points[1].first >> _points[1].second;
		points[0] = toBoardItem(_points[0]);
		points[1] = toBoardItem(_points[1]);
	}

	system("cls");
	player_board.display(toupper(_name[0]));
	list_of_ships.push_back(std::shared_ptr<Ship3>(new Ship3));
	std::cout << "Place third ship: ";
	std::cout << "Size: " << list_of_ships[2]->getSize() << std::endl;
	std::cout << "Start point: "; std::cin >> _points[0].first >> _points[0].second;
	std::cout << "End point: "; std::cin >> _points[1].first >> _points[1].second;
	points[0] = toBoardItem(_points[0]);
	points[1] = toBoardItem(_points[1]);
	while (!list_of_ships[2]->placeShip(points[0], points[1], this->player_board))
	{
		system("cls");
		player_board.display(toupper(_name[0]));
		std::cout << "Incorrect placement. Retry\n";
		std::cout << "Place third ship: ";
		std::cout << "Size: " << list_of_ships[2]->getSize() << std::endl;
		std::cout << "Start point: "; std::cin >> _points[0].first >> _points[0].second;
		std::cout << "End point: "; std::cin >> _points[1].first >> _points[1].second;
		points[0] = toBoardItem(_points[0]);
		points[1] = toBoardItem(_points[1]);
	}

	system("cls");
	player_board.display(toupper(_name[0]));
	list_of_ships.push_back(std::shared_ptr<Ship4>(new Ship4));
	std::cout << "Place fourth ship: ";
	std::cout << "Size: " << list_of_ships[3]->getSize() << std::endl;
	std::cout << "Start point: "; std::cin >> _points[0].first >> _points[0].second;
	std::cout << "End point: "; std::cin >> _points[1].first >> _points[1].second;
	points[0] = toBoardItem(_points[0]);
	points[1] = toBoardItem(_points[1]);
	while (!list_of_ships[3]->placeShip(points[0], points[1], this->player_board))
	{
		system("cls");
		player_board.display(toupper(_name[0]));
		std::cout << "Incorrect placement. Retry\n";
		std::cout << "Place fourth ship: ";
		std::cout << "Size: " << list_of_ships[3]->getSize() << std::endl;
		std::cout << "Start point: "; std::cin >> _points[0].first >> _points[0].second;
		std::cout << "End point: "; std::cin >> _points[1].first >> _points[1].second;
		points[0] = toBoardItem(_points[0]);
		points[1] = toBoardItem(_points[1]);
	}

	system("cls");
	player_board.display(toupper(_name[0]));
	list_of_ships.push_back(std::shared_ptr<Ship5>(new Ship5));
	std::cout << "Place fifth ship: ";
	std::cout << "Size: " << list_of_ships[4]->getSize() << std::endl;
	std::cout << "Start point: "; std::cin >> _points[0].first >> _points[0].second;
	std::cout << "End point: "; std::cin >> _points[1].first >> _points[1].second;
	points[0] = toBoardItem(_points[0]);
	points[1] = toBoardItem(_points[1]);
	while (!list_of_ships[4]->placeShip(points[0], points[1], this->player_board))
	{
		system("cls");
		player_board.display(toupper(_name[0]));
		std::cout << "Incorrect placement. Retry\n";
		std::cout << "Place fifth ship: ";
		std::cout << "Size: " << list_of_ships[4]->getSize() << std::endl;
		std::cout << "Start point: "; std::cin >> _points[0].first >> _points[0].second;
		std::cout << "End point: "; std::cin >> _points[1].first >> _points[1].second;
		points[0] = toBoardItem(_points[0]);
		points[1] = toBoardItem(_points[1]);
	}

	system("cls");
	player_board.display(toupper(_name[0]));
	list_of_ships.push_back(std::shared_ptr<Ship6>(new Ship6));
	std::cout << "Place sixth ship: ";
	std::cout << "Size: " << list_of_ships[5]->getSize() << std::endl;
	std::cout << "Start point: "; std::cin >> _points[0].first >> _points[0].second;
	std::cout << "End point: "; std::cin >> _points[1].first >> _points[1].second;
	points[0] = toBoardItem(_points[0]);
	points[1] = toBoardItem(_points[1]);
	while (!list_of_ships[5]->placeShip(points[0], points[1], this->player_board))
	{
		system("cls");
		player_board.display(toupper(_name[0]));
		std::cout << "Incorrect placement. Retry\n";
		std::cout << "Place sixth ship: ";
		std::cout << "Size: " << list_of_ships[5]->getSize() << std::endl;
		std::cout << "Start point: "; std::cin >> _points[0].first >> _points[0].second;
		std::cout << "End point: "; std::cin >> _points[1].first >> _points[1].second;
		points[0] = toBoardItem(_points[0]);
		points[1] = toBoardItem(_points[1]);
	}
	system("cls");
}

bool Player::replaceShip(const int& index)
{
	if (index < 0 || index > 5)
	{
		return false;
	}
	list_of_ships[index]->destroyShip(this->player_board);
	std::pair<int, int> points[2];
	std::pair<char, int> _points[2];
	std::cout << "Place ship: ";
	std::cout << "Size: " << list_of_ships[index]->getSize() << std::endl;
	std::cout << "Start point: "; std::cin >> _points[0].first >> _points[0].second;
	std::cout << "End point: "; std::cin >> _points[1].first >> _points[1].second;
	points[0] = toBoardItem(_points[0]);
	points[1] = toBoardItem(_points[1]);
	while (!list_of_ships[index]->placeShip(points[0], points[1], this->player_board))
	{
		system("cls");
		player_board.display(toupper(_name[0]));
		std::cout << "Incorrect placement. Retry\n";
		std::cout << "Place first ship: ";
		std::cout << "Size: " << list_of_ships[index]->getSize() << std::endl;
		std::cout << "Start point: "; std::cin >> _points[0].first >> _points[0].second;
		std::cout << "End point: "; std::cin >> _points[1].first >> _points[1].second;
		points[0] = toBoardItem(_points[0]);
		points[1] = toBoardItem(_points[1]);
	}
	return true;
}

bool Player::attack(Player& player)
{
	std::pair<int, int> target;
	std::pair<char, int> temp;
	show(player);
	std::cout << "Point coordinates: ";
	std::cin >> temp.first >> temp.second;
	target = toBoardItem(temp);
	int result = player.fire(target);
	while (!result)
	{
		system("cls");
		player.player_board.show(toupper((player.getName())[0]));
		std::cout << "The point has already been hit. Please, retry.\n";
		std::cout << "Point coordinates: ";
		std::cin >> temp.first >> temp.second;
		target = toBoardItem(temp);
		result = player.fire(target);
	}
	score += result;
	sunken_ships = 0;
	Iterator<std::shared_ptr<Ship>> it(player.list_of_ships);
	while (!it.done())
	{
	    sunken_ships += it.currentItem()->sunken(player.player_board);
		it.next();
	}
	system("cls");
	return (sunken_ships == 6);
}

bool Player::rotateShip(const int& index)
{
	std::pair<int, int> old[2], newp[2];
	old[0] = this->list_of_ships[index]->start;
	old[1] = this->list_of_ships[index]->end;
	if (old[0] == old[1])
	{
		return false;
	}
	else          
	{
		unsigned int size = player_board.getSize() - 1;
		int dif;
		bool parity;
		this->list_of_ships[index]->destroyShip(this->player_board);
		if (old[0].first == old[1].first)
		{
			dif = (old[1].second - old[0].second) + 1;
			parity = dif % 2;
			dif /= 2;
			newp[0] = { (old[0].first - dif),(dif + old[0].second) };
			if (parity)
			{
				newp[1] = { (old[0].first + dif),(dif + old[0].second) };
			}
			else
			{
				newp[1] = { (old[0].first + dif - 1),(dif + old[0].second) };
			}
		}
		else
		{
			dif = (old[1].first - old[0].first) + 1;
			parity = dif % 2;
			dif /= 2;
			newp[0] = { (dif + old[0].first), (old[0].second - dif) };
			if (parity)
			{
				newp[1] = { (dif + old[0].first), (old[0].second + dif) };
			}
			else
			{
				newp[1] = { (dif + old[0].first), (old[0].second + dif - 1) };
			}
		}
		if (this->list_of_ships[index]->placeShip(newp[0], newp[1], this->player_board))
		{
			return true;
		}  
		else
		{
			this->list_of_ships[index]->placeShip(old[0], old[1], this->player_board);
			return false;
		}
	}
}

void Player::save(std::ofstream& g) const
{
	g << score << '\n';
	g << sunken_ships << '\n';
	g << _name << '\n';
	player_board.save(g);
	Iterator<std::shared_ptr<Ship>> it(list_of_ships);
	it.first();
	while (!it.done())
	{
		it.currentItem()->save(g);
		it.next();
	}
}

void Player::load(std::ifstream& f)
{
	f >> score;
	f >> sunken_ships;
	f >> _name;
	int _size;
	f >> _size;
	std::unique_ptr<Player> aux = std::make_unique<Player>(_size, _name);
	aux->score = score;
	aux->sunken_ships = sunken_ships;
	*this = std::move(*aux);
	player_board.load(f);
	list_of_ships.push_back(std::shared_ptr<Ship1>(new Ship1));
	list_of_ships.push_back(std::shared_ptr<Ship2>(new Ship2));
	list_of_ships.push_back(std::shared_ptr<Ship3>(new Ship3));
	list_of_ships.push_back(std::shared_ptr<Ship4>(new Ship4));
	list_of_ships.push_back(std::shared_ptr<Ship5>(new Ship5));
	list_of_ships.push_back(std::shared_ptr<Ship6>(new Ship6));
	Iterator<std::shared_ptr<Ship>> it(list_of_ships);
	while (!it.done())
	{
		it.currentItem()->load(f);
		it.next();
	}
}

void Player::show(Player& player) const
{
	system("cls");
	player.player_board.show(toupper((player.getName())[0]));
	std::cout << '\n' << _name << " hits\n";
	std::cout << "Score: " << this->score << std::endl;
	std::cout << "Sunken ships: " << this->sunken_ships << std::endl;
}

std::pair<int, int> Player::toBoardItem(const std::pair<char, int>& temp) const
{
	return std::make_pair(temp.first - 'a', temp.second - 1);
}

int Player::fire(const std::pair<int, int>& point)
{
	int* _point = &player_board.getPoint(point);
	if (!(*_point))
	{
		*_point = 2;
		return -50;
	}
	else if (*_point == 1)
	{
		*_point = 3;
		return 100;
	}
	else
	{
		return 0;
	}

}
