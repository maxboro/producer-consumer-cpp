# Description
Simple example of producer-consumer pattern in C++.

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
Put good to queue: 0-0
Put good to queue: 2-0
Put good to queue: 1-0
Put good to queue: 2-1
Consumer #0 consumed good: 0-0
Put good to queue: 0-1
Put good to queue: 1-1
Consumer #1 consumed good: 1-0
Put good to queue: 2-2
Consumer #0 consumed good: 2-0
Put good to queue: 1-2
Put good to queue: 0-2
Consumer #1 consumed good: 2-1
Consumer #0 consumed good: 0-1
...
Consumer #1 consumed good: 0-150
Put good to queue: 2-227
Consumer #0 consumed good: 2-151
Put good to queue: 0-227
Put good to queue: 0-228
Put good to queue: 2-228
Put good to queue: 1-228
Consumer #0 consumed good: 0-151
Consumer #1 consumed good: 1-151
Put good to queue: 0-229
Put good to queue: 2-229
Put good to queue: 1-229
Consumer #0 consumed good: 2-152
Consumer #1 consumed good: 1-152
^C
Caught signal 2 (SIGINT). Exiting safely...
Put good to queue: 2-230
Consumer #1 consumed good: 0-152
Put good to queue: 0-230
Consumer #0 consumed good: 2-153
Put good to queue: 1-230
Execution is finished
```