#pragma once
#include <algorithm>


template <typename T, typename U>
void deleter(U& container, T&& value)
{
	typename U::iterator it = container.begin();
	it = std::find(container.begin(), container.end(), value);
	if (it != container.end())
	{
		container.erase(it);
		deleter(container, value);
	}

}
template <typename T1, typename T2, typename T3 =	typename T1::value_type>
class predicate_containers
{
	T1& container1;
	T1& container2;
	T2 functor;

public:

	predicate_containers(T1& in_A, T1& in_B, T2 funct) : container1{in_A} , container2{in_B}, functor{funct}
	{
		container1.clear();
		container2.clear();

	};


	predicate_containers(T1& in_A, T1& in_B) : container1{ in_A }, container2{ in_B }, functor{ T2() }
	{
		container1.clear();
		container2.clear();

	};
	predicate_containers& insert(const T3 inp)
	{
		if (functor(inp))
		{
			container1.push_back(inp);
			return *this;
		}
		container2.push_back(inp);
		return *this;
	}

	predicate_containers& erase(const T3 inp)
	{
		if (functor(inp))
		{
			deleter(container1, inp);
			return *this;
		}
		deleter(container2, inp);
		return *this;
	}
	std::size_t size() const
	{
		return container1.size() + container2.size();
	}

	template <typename Iterator>
	predicate_containers& insert(Iterator begin, Iterator end)
	{
		for (auto it = begin; it != end; it++)
		{
			insert(*it);
		}
		return *this;
	}


};