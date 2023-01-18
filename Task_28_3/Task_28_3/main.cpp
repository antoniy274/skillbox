#include "include/WaitersService.h"
#include "include/KitchenService.h"
#include "include/CourierService.h"

//==========    Global      ==========

std::mutex accessControl;

//==========    Functions   ==========

/**
 * @function Initiates waiters service 'startWork' function. To be used in separate thread.
 * @param [in/out] waitersService
 */
void initiateWaitersWork(WaitersService* waitersService)
{
    waitersService->startWork();
}

/**
 * @function Initiates kitchen service 'startWork' function. To be used in separate thread.
 * @param [in/out] kitchenService
 */
void initiateKitchenWork(KitchenService* kitchenService)
{
    kitchenService->startWork();
}

/**
 * @function Initiates courier service 'startWork' function. To be used in separate thread.
 * @param [in/out] courierService
 */
void initiateCouriersWork(CourierService* courierService)
{
    courierService->startWork();
}

int main() {
    std::queue<Order*> incomingOrders;
    std::queue<Order*> readyOrders;

    auto* waitersService = new WaitersService(&accessControl, &incomingOrders);
    auto* kitchenService = new KitchenService(&accessControl, &incomingOrders, &readyOrders);
    auto* courierService = new CourierService(&accessControl, &readyOrders);

    auto* waiterThread = new std::thread(initiateWaitersWork, waitersService);
    auto* kitchenThread = new std::thread(initiateKitchenWork, kitchenService);
    auto* courierThread = new std::thread(initiateCouriersWork, courierService);

    while (true)
    {
        if (courierService->getIfTargetIsReached())
        {
            courierThread->detach();
            waitersService->stopWork();
            waiterThread->detach();
            kitchenService->stopWork();
            kitchenThread->detach();
            break;
        }
    }
    delete courierThread;
    delete waiterThread;
    delete kitchenThread;

    std::cout << "--- Program is finished ---\n";
    return 0;
}