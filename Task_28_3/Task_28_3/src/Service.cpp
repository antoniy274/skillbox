#include "../include/Service.h"

void Service::wait()
{
    std::this_thread::sleep_for(std::chrono::seconds (this->waitTime));
}

Service::Service()
{
    std::srand(time(nullptr));
}

void Service::setMaxWaitTime(const int maxWaitTime)
{
    this->maxWaitTime = maxWaitTime;
}

void Service::setMinWaitTime(const int minWaitTime)
{
    this->minWaitTime = minWaitTime;
}

void Service::generateWaitTime(std::string label)
{
    this->waitTime = std::rand()%(maxWaitTime - minWaitTime + 1) + minWaitTime;
    accessControl->lock();
    printTimeStamp();
    std::cout << "\t - " << getServiceNameText() << ": " << label << " " << waitTime << " [sec].\n";
    accessControl->unlock();
}

void Service::startWork()
{
    isWorking = true;
    accessControl->lock();
    printTimeStamp();
    std::cout << "\t - " << getServiceNameText() << ": work is started.\n";
    accessControl->unlock();
    work();
}

void Service::stopWork()
{
    isWorking = false;
    accessControl->lock();
    printTimeStamp();
    std::cout << "\t - " << getServiceNameText() << ": work is stopped.\n";
    accessControl->unlock();
}

std::string Service::getServiceNameText()
{
    switch (this->serviceName) {
        case WAITERS:
            return "WAITERS";
        case KITCHEN:
            return "KITCHEN";
        case COURIERS:
            return "COURIER";
        default:
            return "NOT_DEFINED";
    }
}

void Service::printTimeStamp()
{
    std::time_t now = time(nullptr);
    std::tm* timeNow = localtime(&now);
    std::cout << std::put_time(timeNow, "%H:%M:%S") << "\t : ";
}