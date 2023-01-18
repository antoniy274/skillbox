#ifndef TASK_28_3_KITCHENSERVICE_H
#define TASK_28_3_KITCHENSERVICE_H

#include "Service.h"

class KitchenService : public Service {

private:
    Order* activeOrder {nullptr};
    void work() override;

public:
    KitchenService(std::mutex* mutex, std::queue<Order*>* inputOrders, std::queue<Order*>* outputOrders);

    /**
     * @method Get the order for cooking.
     * @param [in] Order* order to be got into cooking
     */
    void setActiveOrder(Order* order);
};

#endif //TASK_28_3_KITCHENSERVICE_H