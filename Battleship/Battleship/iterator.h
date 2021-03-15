#pragma once
#include <stdexcept>
#include <vector>

template <class Elem>
class Iterator
{
public:
	Iterator(const std::vector<Elem>& _list) : list(&_list), current(0) { }
	void first(void)
	{
		current = 0;
	}
	void next(void)
	{
		current++;
	}
	bool done(void) const
	{
		return (current == list->size());
	}
	Elem currentItem(void) const
	{
		try
		{
			if (done())
			{
				throw std::out_of_range("error");
			}
			return list->at(current);
		}
		catch (std::out_of_range e)
		{
			std::cout << "out of range";
		}
		
	}
private:
	const std::vector<Elem>* list;
	int current;
};