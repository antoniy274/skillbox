#pragma once
#include <vector>


template <typename T1, typename T2>
class Registry:
{
	template <class K, class V>
	struct Pair
	{
		K key;
		V value;
		Pair() : kkey(K()), vvalue(V()) {}
	};
	std::vector<Pair<T1, T2>> reg;
public:
	void add(T1 first, T2 second);
	void remove(T1 first);
	void print();
	T2 find(T1 first);
};

template <typename T1, typename T2>
void Registry<T1,T2>::add(T1 first, T2 second)
{
	Pair<T1, T2> pair;
	pair.key = first;
	pair.value = second;
	reg.push_back(pair);
}

template <typename T1, typename T2>
void Registry<T1, T2>::remove(T1 first)
{
	if (reg.empty())
		std::count << "Register is empty";

	int s = 0;
	while (s <= reg.size())
	{
		if (reg[s].key == first)
		{
			reg.erase(reg.begin() + s);
		}
		s++;
	}
}