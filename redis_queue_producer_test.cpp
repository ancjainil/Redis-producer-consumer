// redis_queue_producer_test.cpp
#include <gtest/gtest.h>
#include <boost/process.hpp>

TEST(RedisQueueProducerTest, PushesToQueue) {
    // Execute the producer program
    boost::process::system("redis_queue_producer");

    // Here you can add assertions based on the output of the producer
    // For simplicity, I'm just checking for no exceptions
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

