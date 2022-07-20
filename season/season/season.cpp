#include <iostream>

#define SPRING 0
#define SUMMER 1
#define AUTUMN 2
#define WINTER 3

#define CURRENT_SEASON WINTER

int main()
{
#if CURRENT_SEASON == 0
    std::cout << "Spring";
#elif CURRENT_SEASON == 1
    std::cout << "Summer";
#elif CURRENT_SEASON == 2
    std::cout << "Autumn";
#elif CURRENT_SEASON == 3
    std::cout << "Winter";
#endif
}