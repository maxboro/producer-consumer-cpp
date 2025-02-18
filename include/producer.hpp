#ifndef PRODUCER_HPP
#define PRODUCER_HPP

#include <thread>
#include <chrono>

void produce(std::shared_ptr<std::queue<int>> queue_ptr){
     // put elements to queue
     for (int i = 0; i < 10; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        queue_ptr->push(i);
        std::string msg = "Put element to queue: " + std::to_string(i) + "\n";
        std::cout << msg;
    }
}

#endif
