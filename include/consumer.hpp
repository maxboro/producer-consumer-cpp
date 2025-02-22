#ifndef CONSUMER_HPP
#define CONSUMER_HPP

#include <iostream>
#include <queue>
#include <memory>
#include <mutex>
#include <atomic>
#include <thread>
#include <chrono>
#include "good.h"

// Read from queue
void consume(
        std::shared_ptr<std::queue<Good>> queue_ptr, 
        std::shared_ptr<std::mutex> mutex_ptr, 
        std::atomic<bool>* stop_flag_ptr,
        int consumer_id
 )  {
    while (!stop_flag_ptr->load()) {
        Good next_good;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // thread safe get element
        {
            std::lock_guard<std::mutex> lock(*mutex_ptr);
            if (queue_ptr->empty()){ 
                continue; 
            }
            next_good = queue_ptr->front();
            queue_ptr->pop();
        }

        std::string msg = "Consumer #" + std::to_string(consumer_id) + " consumed good: " + next_good.code + "\n";
        std::cout << msg;
    }
}

#endif
