#include "../include/Order.h"

static int COUNTER = 0;

Order::Order()
{
    std::srand(time(nullptr));
    this->orderType = OrderType (std::rand() % ORDER_TYPES_COUNT);
    ++COUNTER;
    orderId = COUNTER;
}

std::string Order::getOrderTypeText()
{
    switch (orderType)
    {
        case PIZZA:
            return "PIZZA";
        case SOUP:
            return "SOUP";
        case STAKE:
            return "STAKE";
        case SALAD:
            return "SALAD";
        case SUSHI:
            return "SUSHI";
        default:
            return "UNDEFINED";
    }
}

int Order::getOrderId()
{
    return this->orderId;
}