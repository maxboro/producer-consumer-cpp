# Description
Simple example of producer-consumer pattern in C++ (currently in development).

# How to run
#### Simulation:
```bash
make           # Builds the project
./bin/exec     # Runs the executable
```

#### Clean:
```bash
make clean     # Cleans up build files
```

# Example 
```terminal
Running
Put element to queue: 0
Put element to queue: 1
Put element to queue: 2
Consume element from queue: 0
Put element to queue: 3
Consume element from queue: 1
Put element to queue: 4
Consume element from queue: 2
Put element to queue: 5
Consume element from queue: 3
Put element to queue: 6
Consume element from queue: 4
Put element to queue: 7
Put element to queue: 8
...
Consume element from queue: 33
Put element to queue: 37
Consume element from queue: 34
Put element to queue: 38
Consume element from queue: 35
Put element to queue: 39
Consume element from queue: 36
Consume element from queue: 37
Put element to queue: 40
^C
Caught signal 2 (SIGINT). Exiting safely...
Put element to queue: 41
Consume element from queue: 38
Execution is finished
```