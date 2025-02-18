#ifndef CONSUMER_HPP
#define CONSUMER_HPP

#include <thread>
#include <chrono>

void consume(std::shared_ptr<std::queue<int>> queue_ptr){
    // Read from queue
    while (!queue_ptr->empty()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        int element = queue_ptr->front();
        std::string msg = "Consume element from queue: " + std::to_string(element) + "\n";
        std::cout << msg;
        queue_ptr->pop();
    }
}

#endif
