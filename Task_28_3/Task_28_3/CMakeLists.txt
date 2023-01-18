cmake_minimum_required(VERSION 3.19)
project(Task_28_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Task_28_3
        main.cpp
        src/Order.cpp include/Order.h src/Service.cpp include/Service.h src/WaitersService.cpp include/WaitersService.h src/KitchenService.cpp include/KitchenService.h src/CourierService.cpp include/CourierService.h)