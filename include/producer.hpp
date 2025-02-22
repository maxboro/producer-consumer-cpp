#ifndef PRODUCER_HPP
#define PRODUCER_HPP

#include <iostream>
#include <queue>
#include <memory>
#include <mutex>
#include <atomic>
#include <thread>
#include <chrono>
#include <string>
#include "good.h"

Good create(int item_id, int producer_id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::string good_code = std::to_string(producer_id) + "-" + std::to_string(item_id);
    Good new_good {item_id, good_code};
    return new_good;
}

// put elements to queue
void produce(
        std::shared_ptr<std::queue<Good>> queue_ptr, 
        std::shared_ptr<std::mutex> mutex_ptr, 
        const std::atomic<bool>* stop_flag_ptr,
        int producer_id
)   {
    int i = 0;
    while (!stop_flag_ptr->load()) {
        Good new_good = create(i, producer_id);

        // thread safe push element
        {
            std::lock_guard<std::mutex> lock(*mutex_ptr);
            queue_ptr->push(new_good);
        }

        std::string msg = "Put good to queue: " + new_good.code + "\n";
        std::cout << msg;
        i++;
    }
}

#endif
