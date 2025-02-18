#ifndef PRODUCER_HPP
#define PRODUCER_HPP

#include <iostream>
#include <queue>
#include <memory>
#include <mutex>
#include <thread>
#include <chrono>

// put elements to queue
void produce(std::shared_ptr<std::queue<int>> queue_ptr, std::shared_ptr<std::mutex> mutex_ptr){
     for (int i = 0; i < 10; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // thread safe push element
        mutex_ptr->lock();
        queue_ptr->push(i);
        mutex_ptr->unlock();

        std::string msg = "Put element to queue: " + std::to_string(i) + "\n";
        std::cout << msg;
    }
}

#endif
