#pragma once
#include <string>
#include <vector>

struct Address
{
    int _tree = -1;
    int _bigbranch = -1;
    int _branch = -1;
};

class House
{
    std::string _nameElf = "none";
    Address _address;

public:
    House();
    ~House();

    const char* getNameElf();
    House* getHouse();
    void setNameElf(const std::string& name);
    void setAddress(Address& address);
    Address* getAddress();
};

class Bigbranch;

class Tree
{
    int _colBegbranch{ 0 };
    Bigbranch* _bigbranch = nullptr;
public:
    Tree();
    ~Tree();
    int getSizeBigbranch();
    Bigbranch* getBigbranch();

};


class Forest
{
    //количество деревьев
    int _size{ 0 };
    //Указатель на массив деревьев
    class Tree* _tree = nullptr;
    //указатели на все созданные дома
    std::vector<class House*> _home;
    void setHouse();
    int numberOFneighbors(struct Address& address);
public:
    Forest(int size = 5);
    ~Forest();
    void setNameElf();
    void printElfName();
    void findElf(const std::string& name);
};

class Branch : public House
{
    // House* _house = nullptr;
public:
    Branch();
    ~Branch();
};

class Branch;

class Bigbranch : public House
{
    int _colbranch{ 0 };
    Branch* _branch = nullptr;
    //House* _house = nullptr;
public:
    Bigbranch();
    ~Bigbranch();
    int getSizeBranch();
    Branch* getBranch();

};