#include <iostream>
#include <ctime>
#include <thread>
#include <mutex>
#include <vector>

std::mutex waitingCooking;
std::mutex activitiesStation;



void cooking();

int main()
{
    cooking();
}

void cooking() {
    std::vector <std::string> deliveryFood;
    do {
        std::srand(std::time(nullptr));
        int s = std::rand() % 5 + 5;
        std::string dish[5] = { "pizza", "soup", "steak", "salad", "sushi" };

        std::vector <std::string> cookingDish;
        std::this_thread::sleep_for(std::chrono::seconds(s));
        //тут вставка
//-----------------------------------
        waitingCooking.lock();
        cookingDish.push_back(dish[std::rand() % 5]);
        std::cout << cookingDish.size() << " waiting cooking" << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 10 + 5));
        waitingCooking.unlock();
//------------------------------------
        std::vector <std::string> readyMeal;
        //тут вставка
        readyMeal.insert(readyMeal.end(), cookingDish.begin(), cookingDish.end());
        std::cout << readyMeal.size() << " waiting to delivery" << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(30));
        //std::vector <std::string> deliveryFood;
        //тут вставка
        //При каждой ставке нужен свой mutex?
        deliveryFood.insert(deliveryFood.end(), readyMeal.begin(), readyMeal.end());
        std::cout << deliveryFood.size() << " orders delivered" << "\n";

        readyMeal.clear();
        cookingDish.clear();

    } while (deliveryFood.size() < 10);

    std::cout << deliveryFood.size() << " deliveries were made";
}
