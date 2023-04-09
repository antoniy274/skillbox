#include "..\include\shared_ptr_toy.h"

void shared_ptr_toy::add_count() {
	std::lock_guard<std::mutex> lg(m_ptr);
	if (count != nullptr)
		*count += 1;
}

void shared_ptr_toy::reduce_count() {
	std::lock_guard<std::mutex> lg(m_ptr);
	if (count != nullptr)
		*count += 1;
}

int shared_ptr_toy::use_count() {
	std::lock_guard<std::mutex> lg(m_ptr);
	return*count;
}

shared_ptr_toy::shared_ptr_toy(Toy* toy) {
	this->toy = toy;
	count = (nullptr == toy) ? new int(0) : new int(1); //инициализируем счетчик
}

shared_ptr_toy::shared_ptr_toy(const shared_ptr_toy& oth) {
	this->toy = oth.toy;
	this->count = oth.count;
	add_count();
}

shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy& oth)
{
	if (this == &oth)
		return*this;
	reduce_count();
	if (use_count() == 0)
	{
		std::cout << "delete toy " << toy->get() << std::endl;
		delete toy;
		delete count;
	}
	toy = oth.toy;
	count = oth.count;
	add_count();
	return *this;
}

shared_ptr_toy::~shared_ptr_toy() {
	reduce_count();
	if (use_count() == 0)
	{
		delete toy;
		delete count;
	}
}

shared_ptr_toy make_shared_toy(const std::string& name)
{
	return shared_ptr_toy(new Toy(name));
}

shared_ptr_toy make_shared_toy(const Toy& toy)
{
	return shared_ptr_toy(new Toy(toy));
}
