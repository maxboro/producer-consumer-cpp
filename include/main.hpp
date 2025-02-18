#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <queue>
#include <memory>
#include <mutex>
#include "producer.hpp"
#include "consumer.hpp"

// Simple queue use example
int main(){
    std::cout << "Running" << std::endl;
    auto queue_ptr = std::make_shared<std::queue<int>>();
    auto mutex_ptr = std::make_shared<std::mutex>();
    
    std::thread producer_thread(produce, queue_ptr, mutex_ptr);
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::thread consumer_thread(consume, queue_ptr, mutex_ptr);

    producer_thread.join();
    consumer_thread.join();
    std::cout << "Execution is finished" << std::endl;
    return 0;
}

#endif
