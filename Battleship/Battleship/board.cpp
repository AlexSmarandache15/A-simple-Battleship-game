#include "board.h"

Board::Board(const int& size)
{
	_table.resize(size);
	for (auto& iterator : _table)
	{
		iterator.resize(size);
	}
}

Board::~Board(void)
{
	_table.clear();
}

int& Board::getPoint(const std::pair<int, int>& point)
{
	return _table[point.first][point.second];
}

unsigned int Board::getSize(void) const
{
	return _table.size();
}

void Board::show(const char& init) const
{
	unsigned int _size = this->_table.size();
	int index = 0;
	std::cout << " " << init << " |  ";
	for (int i = 0; i < _size; i++)
	{
		if (index < 9)
		{
			std::cout << ++index << "  ";
		}
		else
		{
			std::cout << ++index << " ";
		}
	}
	std::cout << std::endl;
	std::cout << "---| ";
	for (int i = 0; i < _size; i++)
	{
		std::cout << "---";
	}
	std::cout << std::endl;
	char temp = 'a';
	for (const auto& row : _table)
	{
		std::cout << temp++ << "  |  ";
		for (const auto& iterator : row)
		{
			if (iterator == 2)
			{
				std::cout << "R";
			}
			else if (iterator == 3)
			{
				std::cout << "B";
			}
			else
			{
				std::cout << "W";
			}
			std::cout << "  ";
		}
		std::cout << '\n';
	}
	std::cout << std::endl;
	std::cout << "W - the square has not been hit yet\n";
	std::cout << "R - missed shot\n";
	std::cout << "B - ship hit\n";
}

void Board::display(const char& init) const
{
	unsigned int _size = this->_table.size();
	int index = 0;
	std::cout  << " " << init << " |  ";
	for (int i = 0; i < _size; i++)
	{
		if (index < 9)
		{
			std::cout << ++index << "  ";
		}
		else
		{
			std::cout << ++index << " ";
		}
	}
	std::cout << std::endl;
	std::cout << "---| ";
	for (int i = 0; i < _size; i++)
	{
		std::cout << "---";
	}
	std::cout << std::endl;
	char temp = 'a';
	for (const auto& row : _table)
	{
		std::cout << temp++ << "  |  ";
		for (const auto& iterator : row)
		{
			std::cout << iterator << "  ";
		}
		std::cout << '\n';
	}
	std::cout << std::endl;
	std::cout << "1 - a part of the ship is placed there\n";
	std::cout << "0 - the square is empty\n\n";
}

bool Board::valid(const std::pair<int, int>& point) const
{
	unsigned int size = _table.size();
	if (!point.first && !point.second)
	{
		return (!_table[0][1] && !_table[1][0] && !_table[0][0]);
	}
	else if (!point.first && point.second == (size - 1))
	{
		return (!_table[0][size - 2] && !_table[1][size - 1] && !_table[0][size - 1]);
	}
	else if (!point.second && point.first == (size - 1))
	{
		return (!_table[size - 1][0] && !_table[size - 2][0] && !_table[size - 1][1]);
	}
	else if ((point.first == (size - 1)) && (point.second == (size - 1)))
	{
		return (!_table[size - 1][size - 1] && !_table[size - 2][size - 1] && !_table[size - 1][size - 2]);
	}
	else if (!point.first)
	{
		return (!_table[0][point.second - 1] && !_table[0][point.second] && !_table[0][point.second + 1] && !_table[1][point.second]);
	}
	else if (!point.second)
	{
		return (!_table[point.first][0] && !_table[point.first - 1][0] && !_table[point.first + 1][0] && !_table[point.first][1]);
	}
	else if (point.first == (size - 1))
	{
		return (!_table[size - 1][point.second] && !_table[size - 1][point.second - 1] && !_table[size - 1][point.second + 1] && !_table[size -2][point.second]);
	}
	else if (point.second == (size - 1))
	{
		return(!_table[point.first][size - 1] && !_table[point.first][size - 2] && !_table[point.first - 1][size - 1] && !_table[point.first + 1][size - 1]);
	}
	else
	{
		return (!_table[point.first][point.second] && !_table[point.first - 1][point.second] && !_table[point.first + 1][point.second] && !_table[point.first][point.second - 1] && !_table[point.first][point.second + 1]);
	}
}

void Board::save(std::ofstream& g) const
{
	g << _table.size() << '\n';
	for (const auto& row : _table)
	{
		for (const auto& iterator : row)
		{
			g << iterator << " ";
		}
		g << '\n';
	}
}

void Board::load(std::ifstream& f)
{
	for (auto& row : _table)
	{
		for (auto& iterator : row)
		{
			f >> iterator;
		}
	}
}
