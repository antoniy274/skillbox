#include "../include/WaitersService.h"

WaitersService::WaitersService(std::mutex *mutex, std::queue<Order*>* outputOrders)
{
    this->serviceName = WAITERS;
    this->accessControl = mutex;
    this->outputOrders = outputOrders;
    setMinWaitTime(5);
    setMaxWaitTime(10);
}

void WaitersService::work()
{
    do {
        generateWaitTime("next order is awaited in");
        wait();
        Order* order = new Order();
        accessControl->lock();
        outputOrders->push(order);
        printTimeStamp();
        std::cout << "\t - " << getServiceNameText() << ": order #" << order->getOrderId() << " (" << order->getOrderTypeText() << ") is received.\n";
        accessControl->unlock();
    } while (isWorking);
}