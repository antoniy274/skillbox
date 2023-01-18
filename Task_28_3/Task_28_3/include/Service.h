#ifndef TASK_28_3_SERVICE_H
#define TASK_28_3_SERVICE_H

#include <thread>
#include <mutex>
#include <queue>
#include <ctime>
#include <iomanip>
#include "Order.h"

enum ServiceName{
    WAITERS,
    KITCHEN,
    COURIERS,
    NOT_DEFINED
};

class Service {

protected:

    ServiceName serviceName {NOT_DEFINED};
    int minWaitTime {0};
    int maxWaitTime {0};
    int waitTime {0};
    std::mutex* accessControl = nullptr;
    std::queue<Order*>* inputOrders = nullptr;
    std::queue<Order*>* outputOrders = nullptr;
    bool isWorking = false;

    Service();
    void wait();
    /**
     * @method Set maximal wait time in seconds.
     * @param [in] maxWaitTime int
     */
    void setMaxWaitTime(const int maxWaitTime);

    /**
     * @method Set minimal wait time in seconds.
     * @param [in] minWaitTime int
     */
    void setMinWaitTime(const int minWaitTime);

    /**
     * @method Generate wait time between min and max wait time.
     * @param [in] label std::string to be printed in console as comment for wait time
     */
    void generateWaitTime(std::string label);

    /**
     * @method Print in console current time.
     */
    void printTimeStamp();

    /**
     * @method Main service activity. To be initiated by 'startWork' method.
     */
    virtual void work() = 0;

public:

    /**
     * @method Initiate 'work' method. Set 'isWorking' flag to true. To be used with thread.
     */
    void startWork();

    /**
     * @method Set 'isWorking' flag to false. To be used with thread.
     */
    void stopWork();

    /**
     * @method Get the service name as std::string.
     * @return [out] std::string service name text
     */
    std::string getServiceNameText();

};

#endif //TASK_28_3_SERVICE_H