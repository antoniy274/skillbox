#pragma once

#include <string>
#include <map>
#include <exception>

class exception_shop :std::exception
{
	std::string _message;

public:
	exception_shop(const std::string& message) : _message(message) {}
	const char* what()const noexcept override
	{
		return _message.c_str();
	}
};

class Shop
{
	std::map<std::string, int> shopItems;
	std::size_t shopSetw = 0;
public:
	Shop() = default;
	~Shop() = default;
	Shop(const Shop& other) = default;
	Shop& operator=(Shop& other) = default;

	//Inser new Article and count
	void insert(const std::string& article, int count);

	//Add count to existing article
	void add(const std::string& article, int count);

	//Remove count to existing article
	void remove(const std::string article, int count);

	//Return count to existing article
	int count_article(const std::string& article) const;

	//Return size article
	int count_product() const;

	//Show database
	void show() const;
};