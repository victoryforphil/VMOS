#include "gtest/gtest.h"
#include "core/threading/queue_manager.hpp"
#include "core/threading/message_queue.hpp"


TEST(QueueTest, ManualMessageQueue){
  MessageQueue<int>* testQueue = new MessageQueue<int>(10);
  EXPECT_TRUE(testQueue != nullptr);
  delete testQueue;
}

TEST(QueueTest, MessageQueueWrite){
  MessageQueue<int>* testQueue = new MessageQueue<int>(10);
  EXPECT_EQ(testQueue->write(100), 1);
  delete testQueue;
}

TEST(QueueTest, MessageQueueWriteMax){
  MessageQueue<int>* testQueue = new MessageQueue<int>(10);


  for(int i=0;i<50;i++){
    testQueue->write(i);
  }

  EXPECT_EQ(testQueue->write(100), 9);

  delete testQueue;
}

TEST(QueueTest, MessageQueueGetLatest){
  MessageQueue<int>* testQueue = new MessageQueue<int>(10);
  int val = 0;
  testQueue->write(100);
  testQueue->getLatest(val);
  EXPECT_EQ(val, 100);
  testQueue->write(50);
  testQueue->write(75);
  testQueue->getLatest(val);
  EXPECT_EQ(val, 75);
  delete testQueue;
}