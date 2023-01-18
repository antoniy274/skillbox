#include "../include/CourierService.h"

CourierService::CourierService(std::mutex *mutex, std::queue<Order *> *inputOrders)
{
    this->serviceName = COURIERS;
    this->accessControl = mutex;
    this->inputOrders = inputOrders;
    setMinWaitTime(30);
    setMaxWaitTime(30);
}

void CourierService::work() {
    do {
        if (!(inputOrders->empty()))
        {
            accessControl->lock();
            while (!(inputOrders->empty()))
            {
                printTimeStamp();
                std::cout << "\t - " << getServiceNameText()
                          << ": order #" << inputOrders->front()->getOrderId()
                          << " (" << inputOrders->front()->getOrderTypeText()
                          << ") is shipped.\n";
                inputOrders->pop();
                ++ordersShipped;
                if (ordersShipped >= ORDERS_TARGET_COUNT)
                {
                    std::cout << "\t - " << getServiceNameText() << ": "
                              << ORDERS_TARGET_COUNT << " orders are shipped. Target is reached.\n";

                    accessControl->unlock();
                    stopWork();
                    break;
                }
            }
            accessControl->unlock();
            if (!isWorking) break;
            generateWaitTime("next orders will be shipped in");
            wait();
        }
    } while (isWorking);
}

bool CourierService::getIfTargetIsReached()
{
    return (ordersShipped >= ORDERS_TARGET_COUNT);
}
