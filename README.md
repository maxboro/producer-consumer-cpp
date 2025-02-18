# Description
Simple example of producer-consumer pattern in C++ (currently in development).

# How to run
#### Simulation:
```bash
make           # Builds the project
./bin/exec     # Runs the executable
```

#### Unit tests:
```bash
make test      # Builds the unit tests
./bin/tests    # Runs the executable of tests
```

#### Clean:
```bash
make clean     # Cleans up build files
```
# Settings
-
# Credits
Testing framework: [Catch2](https://github.com/catchorg/Catch2) (licensed under the Boost Software License)

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
Consume element from queue: 5
Put element to queue: 8
Consume element from queue: 6
Put element to queue: 9
Consume element from queue: 7
Consume element from queue: 8
Consume element from queue: 9
Execution is finished
```