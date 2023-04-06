#pragma once
#include <iostream>
#include <string>
#include <mutex>

class Toy
{
    std::string _ltoy;

public:
    Toy(const std::string& toy) : _ltoy(toy) { std::cout << "create toy" << std::endl; }

    Toy() : Toy("no name") {}
    std::string get()
    {
        return _ltoy;
    }

};

class shared_ptr_toy {
private:
    Toy* toy = nullptr;
    int* count = nullptr;
    std::mutex m_ptr;
    void add_count();
    void reduce_count();
public:
    int use_count();
    shared_ptr_toy() :shared_ptr_toy(nullptr) {};
    shared_ptr_toy(Toy* toy);
    shared_ptr_toy(const shared_ptr_toy& oth);
    shared_ptr_toy& operator=(const shared_ptr_toy& oth);
    ~shared_ptr_toy();

    Toy* operator->() { return toy; }
    Toy& operator*() { return *toy; }
};

shared_ptr_toy make_shared_toy(const std::string& name);
shared_ptr_toy make_shared_toy(const Toy& toy);