#ifndef TASK_28_3_COURIERSERVICE_H
#define TASK_28_3_COURIERSERVICE_H

#include "Service.h"

class CourierService : public Service {

private:
    const int ORDERS_TARGET_COUNT = 10;
    void work() override;
    int ordersShipped {0};

public:

    CourierService(std::mutex* mutex, std::queue<Order*>* inputOrders);

    /**
     * @method Return if shipped orders count is equal or higher than target.
     * @return [out] true if target is reached or higher.
     */
    bool getIfTargetIsReached();
};

#endif //TASK_28_3_COURIERSERVICE_H