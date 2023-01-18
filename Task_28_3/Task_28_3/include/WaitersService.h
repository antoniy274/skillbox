#ifndef TASK_28_3_WAITERSSERVICE_H
#define TASK_28_3_WAITERSSERVICE_H

#include "Service.h"

class WaitersService : public Service {

private:
    void work() override;

public:
    WaitersService(std::mutex* mutex, std::queue<Order*>* outputOrders);
};

#endif //TASK_28_3_WAITERSSERVICE_H