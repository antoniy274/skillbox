#include <random>
#include <iostream>
#include <stdexcept>
#include <random>

#include "lake.h"

int Fishing::random(int a, int b)
{
	std::random_device rd;
	std::mt19937 ran(rd());
	std::uniform_int_distribution<> gen_mt(a, b);
	return gen_mt(ran);
}

Fishing::Fishing()
{
	constexpr auto size_pond = sizeof(pond) / sizeof(pond[0]);

	for (std::size_t i = 0; i < size_pond; ++i)
	{
		pond[i] = Items::EMPTY;
	}
	pond[random(0, size_pond - 1)] = Items::FISH;

	int count_pond = 0;

	while (count_pond != SizeBoot)
	{
		const auto rand = random(0, size_pond - 1);
		if (Items::EMPTY == pond[rand])
		{
			pond[rand] = Items::BOOT;
			++count_pond;
		}
	}
}

void Fishing::catchFish(std::size_t p) const
{
	constexpr auto size_pond = sizeof(pond) / sizeof(pond[0]);
	if (p >= size_pond)
		throw std::out_of_range("Error: fishing sector must be 0 to 8");

	if (pond[p] == Items::FISH)
		throw exception_fish("Good job, you caught a fish");

	if (pond[p] == Items::BOOT)
		throw exception_fish("Ha ha, you caught the boot");

	if(pond[p] == Items::EMPTY)
	{
		++colFishing;
		throw std::runtime_error("There are no fish here, try again");
	}
}