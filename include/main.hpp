#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <queue>
#include <memory>
#include <mutex>
#include <atomic>
#include <csignal>
#include "producer.hpp"
#include "consumer.hpp"
#include "good.h"

// Global atomic flag to signal threads to stop
std::atomic<bool> stop_flag(false);

void handle_sigint(int signal) {
    printf("\nCaught signal %d (SIGINT). Exiting safely...\n", signal);
    stop_flag.store(true);
}

// Simple queue use example
int main(){
    // Register the signal handler
    std::signal(SIGINT, handle_sigint);

    std::cout << "Running" << std::endl;
    auto queue_ptr = std::make_shared<std::queue<Good>>();
    auto mutex_ptr = std::make_shared<std::mutex>();
    
    std::thread producer_thread(produce, queue_ptr, mutex_ptr, &stop_flag, 1);
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    std::thread consumer_thread(consume, queue_ptr, mutex_ptr, &stop_flag, 1);

    producer_thread.join();
    consumer_thread.join();
    std::cout << "Execution is finished" << std::endl;
    return 0;
}

#endif
