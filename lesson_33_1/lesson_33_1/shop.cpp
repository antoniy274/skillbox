#include <iostream>
#include <iomanip>

#include "shop.h"

void Shop::insert(const std::string& article, int count)
{
	if (count == SIZE_MAX)
		throw exception_shop("Error count");

	auto it_find = shopItems.find(article);

	if (it_find != shopItems.find(article))
	{
		throw exception_shop("Such an an article [" + article + "] already exists, use \"ADD\" to add the prouct");
	}
	else
	{
		shopItems.insert(std::make_pair(article, count));
		shopSetw = std::max(shopSetw, article.size());
	}
}

void Shop::add(const std::string& article, int count) {
	if (count == SIZE_MAX)
		throw exception_shop("Error count");
	
	auto it_find = shopItems.find(article);

	if (it_find != shopItems.end())
	{
		it_find->second += count;
	}
	else
	{
		throw exception_shop("Article " + article + " not found");
	}
}

void Shop::remove(const std::string article, int count)
{
	if (count == SIZE_MAX)
		throw exception_shop("Error count");

	auto it_find = shopItems.find(article);

	if (it_find != shopItems.end())
	{
		if (count > it_find->second)
		{
			throw exception_shop("Error: The quantity being deleted is larger than the existing one");
		}
		else
		{
			it_find->second -= count;
		}
	}
	else
	{
		throw exception_shop("Article " + article + " not found");
	}
}

int Shop::count_article(const std::string& article) const
{
	auto it_find = shopItems.find(article);

	if (it_find != shopItems.end())
	{
		return it_find->second;
	}
	else
	{
		throw exception_shop("Article [" + article + "] not found");
	}
}

int Shop::count_product() const
{
	return shopItems.size();
}

void Shop::show() const
{
	for (auto it = shopItems.begin(); it != shopItems.end(); ++it)
	{
		std::cout << std::setw(static_cast<int>(shopSetw)) << std::left
			<< it->first << " : " << it->second << std::endl;
	}
}