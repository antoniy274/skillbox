#pragma once
#include <vector>
#include <iostream>


template <typename T1, typename T2>
class Registr
{
public:

    template <class K, class V>
    struct Pair
    {
        K _key;
        V _value;
        Pair() : _key(K()), _value(V()) {}
    };

private:
    std::vector<Pair<T1, T2>> _reg;
    int binary_get_index(const T1& key) const
    {
        if (_reg.empty())
            return -1;

        int low = 0;
        int high = static_cast<int>(_reg.size());
        high -= 1;
        while (low <= high)
        {
            int midle = (low + high) / 2;
            Pair<T1, T2> el = _reg[static_cast<std::size_t>(midle)];
            if (el._key == key)
                return midle;
            if (el._key > key)
            {
                high = midle - 1;
            }
            else
            {
                low = midle + 1;
            }
        }
        return -1;
    }

public:
    Registr() {}
    Registr(const T1& key, const T2& value)
    {
        add(key, value);
    }

    Pair<T1, T2> add(const T1& key, const T2& value)
    {
        Pair<T1, T2> pair;
        pair._key = key;
        pair._value = value;
        _reg.push_back(pair);
        return _reg.back();
    }

    T2& operator[](const T1& key)
    {
        for (Pair<T1, T2>& pair : _reg)
        {
            if (pair._key == key)
                return pair._value;
        }
        add(key, T2());
        return _reg.back()._value;
    }

    void print() const
    {
        for (const Pair<T1, T2>& pair : _reg)
            std::cout << pair._key << " " << pair._value << std::endl;
    }

    T2 find(const T1& key) const
    {
        int index = binary_get_index(key);
        if (index == -1)
            return T2();
        return _reg[static_cast<std::size_t>(index)]._value;
    }

    void remove(const T1& key)
    {
        int index = binary_get_index(key);
        _reg.erase(_reg.begin() + index);
    }

};