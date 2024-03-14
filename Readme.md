


### Redis Queue Producer and Consumer

This repository contains C++ programs for a Redis queue producer and consumer using the Boost Redis client.

### Requirements

- C++ compiler (with C++14 support)
- Boost libraries
- Redis server

## Installation

### Install Boost Libraries

Make sure you have Boost installed on your system. You can install it using your package manager:

```bash
sudo dnf install boost-devel
```

### Install Redis

Install Redis using the package manager:

```bash
sudo dnf install redis
```

## Usage

### Running Redis Server

Start the Redis server:

```bash
sudo systemctl start redis
```

### Compile Programs

Compile the producer and consumer programs:

```bash
g++ -std=c++11 -o redis_queue_producer redis_queue_producer.cpp -lboost_system -lboost_thread -lpthread
g++ -std=c++11 -o redis_queue_consumer redis_queue_consumer.cpp -lboost_system -lboost_thread -lpthread
```

### Running Producer

Run the producer program:

```bash
./redis_queue_producer
```

Enter a message when prompted, and it will be pushed onto the Redis queue.

### Running Consumer

Run the consumer program:

```bash
./redis_queue_consumer
```

It will pop a message from the Redis queue and display it.

### Running Unit Test

Compile the unit test program:

```bash
g++ -std=c++14 -o redis_queue_producer_test redis_queue_producer_test.cpp -lgtest -lgtest_main -pthread
```

Run the unit test:

```bash
./redis_queue_producer_test
```


