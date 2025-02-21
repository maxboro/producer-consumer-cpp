#ifndef CONSUMER_HPP
#define CONSUMER_HPP

#include <iostream>
#include <queue>
#include <memory>
#include <mutex>
#include <atomic>
#include <thread>
#include <chrono>

// Read from queue
void consume(std::shared_ptr<std::queue<int>> queue_ptr, std::shared_ptr<std::mutex> mutex_ptr, std::shared_ptr<std::atomic<bool>> stop_flag_ptr){
    while (!queue_ptr->empty() && !stop_flag_ptr->load()) {
        int element;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // thread safe get element
        {
            std::lock_guard<std::mutex> lock(*mutex_ptr);
            element = queue_ptr->front();
            queue_ptr->pop();
        }

        std::string msg = "Consume element from queue: " + std::to_string(element) + "\n";
        std::cout << msg;
    }
}

#endif
