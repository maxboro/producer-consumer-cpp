#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <queue>
#include "producer.hpp"
#include "consumer.hpp"

// Simple queue use example
int main(){
    std::cout << "Running" << std::endl;
    std::queue <int> queue_inst;

    // put elements to queue
    for (int i = 0; i < 10; i++){
        queue_inst.push(i);
    }

    // Read from queue
    while (!queue_inst.empty()) {
        int element = queue_inst.front();
        std::cout << "Element from queue: " << element << std::endl;
        queue_inst.pop();
    }
    std::cout << "Finished execution" << std::endl;
    return 0;
}

#endif
