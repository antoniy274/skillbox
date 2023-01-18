#include "../include/KitchenService.h"

KitchenService::KitchenService(std::mutex *mutex, std::queue<Order *> *inputOrders, std::queue<Order *> *outputOrders)
{
    this->serviceName = KITCHEN;
    this->accessControl = mutex;
    this->inputOrders = inputOrders;
    this->outputOrders = outputOrders;
    setMinWaitTime(5);
    setMaxWaitTime(15);
}

void KitchenService::setActiveOrder(Order *order)
{
    this->activeOrder = order;
}

void KitchenService::work()
{
    do {
        if (this->activeOrder == nullptr)
        {
            if (!(inputOrders->empty()))
            {
                accessControl->lock();
                setActiveOrder(inputOrders->front());
                inputOrders->pop();
                printTimeStamp();
                std::cout << "\t - " << getServiceNameText() << ": the order #" << activeOrder->getOrderId() << " is in work.\n";
                accessControl->unlock();
                generateWaitTime("the cooking time is");
                wait();
                accessControl->lock();
                outputOrders->push(activeOrder);
                printTimeStamp();
                std::cout << "\t - " << getServiceNameText() << ": the order #" << activeOrder->getOrderId() << " is ready.\n";
                activeOrder = nullptr;
                accessControl->unlock();
            }
        }
    } while (isWorking);
}