#ifndef TASK_28_3_ORDER_H
#define TASK_28_3_ORDER_H

#include <iostream>
#include <random>

enum OrderType{
    PIZZA = 0,
    SOUP = 1,
    STAKE = 2,
    SALAD = 3,
    SUSHI = 4,
    UNDEFINED = 99
};

class Order {

private:
    int orderId;
    const int ORDER_TYPES_COUNT = 5;
    OrderType orderType;

public:
    Order();

    /**
     * @method Return the std::string with order type name.
     * @return [out] std::string Order type name
     */
    std::string getOrderTypeText();

    /**
     * @method Return integer with order ID number.
     * @return [out] int Order ID
     */
    int getOrderId();
};

#endif //TASK_28_3_ORDER_H