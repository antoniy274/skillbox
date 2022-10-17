#include "elf_village.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
//#include <algorithm>


House::House()
{

}

House::~House()
{

}

House* House::getHouse()
{
    return this;
}

const char* House::getNameElf()
{
    return _nameElf.c_str();
}

void House::setNameElf(const std::string& name)
{
    _nameElf = name;
}

void House::setAddress(Address& address)
{
    _address = address;
}

Address* House::getAddress()
{
    return &_address;
}


Bigbranch::Bigbranch()
{
    _colbranch = 2 + rand() % 2;
    _branch = new Branch[_colbranch];
    // _house = new House();
}

Bigbranch::~Bigbranch()
{
    //delete _house;
    delete[] _branch;
}

int Bigbranch::getSizeBranch()
{
    return _colbranch;
}

Branch* Bigbranch::getBranch()
{
    return _branch;
}


Forest::Forest(int size) : _size(size)
{
    std::srand(std::time(nullptr));
    _tree = new Tree[_size];
    setHouse();
}

Forest::~Forest()
{
    delete[] _tree;
}

void Forest::setHouse()
{
    Address add;
    for (int tree = 0; tree < _size; ++tree)
    {
        for (int bigbrach = 0; bigbrach < _tree[tree].getSizeBigbranch(); ++bigbrach)
        {
            _home.push_back(_tree[tree].getBigbranch()[bigbrach].getHouse());
            add._tree = tree;
            add._bigbranch = bigbrach;
            add._branch = -1;
            _home.back()->setAddress(add);
            for (int branch = 0; branch < _tree[tree].getBigbranch()[bigbrach].getSizeBranch(); ++branch)
            {
                _home.push_back(_tree[tree].getBigbranch()[bigbrach].getBranch()[branch].getHouse());
                add._tree = tree;
                add._bigbranch = bigbrach;
                add._branch = branch;
                _home.back()->setAddress(add);
            }
        }
    }

    std::cout << _home.size() << " Elfes are inhabited" << std::endl;
}

void Forest::printElfName()
{
    for (const auto& s : _home)
        std::cout << s->getNameElf() << ": Address ----> " << s->getAddress()->_tree
        << ":" << s->getAddress()->_bigbranch
        << ":" << s->getAddress()->_branch << std::endl;
}

void Forest::setNameElf()
{
    std::string name;
    int i = 0;
    for (const auto& s : _home)
    {
        std::cout << "Enter name Elf number " << ++i << ": ";
        getline(std::cin, name);
        s->setNameElf(name);
    }
}

void Forest::findElf(const std::string& name)
{
    for (int i = 0; i < _home.size(); ++i)
    {
        if (_home[i]->getNameElf() == name)
        {
            auto ret = _home[i]->getAddress();
            std::cout << "Number of neighbors: " << numberOFneighbors(*ret) << std::endl;

            return;
        }

    }
    std::cout << "Not found " << name << std::endl;
}

int Forest::numberOFneighbors(Address& address)
{
    if (address._tree == -1) return -1;
    if (address._bigbranch == -1) return -1;
    int col = 0;
    if (_tree[address._tree].getBigbranch()[address._bigbranch].getNameElf() != "none")
    {
        ++col;
    }
    for (int branch = 0; branch < _tree[address._tree].getBigbranch()[address._bigbranch].getSizeBranch(); ++branch)
    {
        if (_tree[address._tree].getBigbranch()[address._bigbranch].getBranch()[address._branch].getNameElf() != "none")
        {
            ++col;
        }
    }
    return --col;
}

Branch::Branch()
{

    //  _house = new House();
}

Branch::~Branch()
{

    //  delete _house;
}

Tree::Tree()
{
    _colBegbranch = 3 + rand() % 3;

    _bigbranch = new Bigbranch[_colBegbranch];

}

Tree::~Tree()
{
    delete[] _bigbranch;
}

int Tree::getSizeBigbranch()
{
    return _colBegbranch;
}

Bigbranch* Tree::getBigbranch()
{
    return _bigbranch;
}
