#include <iostream>
#include "lake.h"


int main()
{
    Fishing game;
    bool fishing = true;

    while (fishing)
    {
        std::cout << "Enter number pond to fishing: ";
        std::size_t pond;
        std::cin >> pond;
        try
        {
            game.catchFish(pond);
        }
        catch (const exception_fish& e)
        {
            std::cout << e.what() << " in " << game.attempts() << " attempts\n";
            fishing = false;
        }
        catch (const exception_boot& e)
        {
            std::cout << e.what() << '\n';
            fishing = false;
        }
        catch (const std::runtime_error& e)
        {
            std::cout << e.what() << '\n';
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}