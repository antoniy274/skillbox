#pragma once

#include <array>
#include <execution>
#include <string>

class exception_fish :std::exception
{
	std::string message;
public:
	exception_fish(const std::string m) : message(m) {};
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};

class exception_boot : std::exception
{
	std::string message;
public:
	exception_boot(const std::string m) :message(m) {};
	const char* what() const noexcept override
	{
		return message.c_str();
	}
};

class Fishing
{
	enum class Items
	{
		FISH,
		BOOT,
		EMPTY
	};
	int SizeBoot = 3;
	mutable int colFishing = 1;
	Items pond[9];

	int random(int a, int b);

public:
	Fishing();

	void catchFish(std::size_t pond)const;
	int attempts() const { return colFishing; }
};