//
// Created by Dylan Verrezen on 2016/05/27.
//

#include "gtest/gtest.h"
#include "queue.h"

TEST(QueueTest, ConstructorStartEmpty) {
    Queue<int> q;
    ASSERT_TRUE(q.is_empty());
    ASSERT_EQ(0, q.get_size());
}

TEST(QueueTest, AddSingleElement) {
    Queue<int> q;
    ASSERT_TRUE(q.push(1));
    ASSERT_EQ(1, q.get_size());
    ASSERT_FALSE(q.is_empty());
}

TEST(QueueTest, AddAndGetSingle) {
    Queue<int> q;
    ASSERT_TRUE(q.push(1));
    ASSERT_EQ(1, q.pop());
    ASSERT_TRUE(q.is_empty());
    ASSERT_EQ(0, q.get_size());
}

TEST(QueueTest, ThrowsExeptPopWhenEmpty) {
    Queue<int> q;
    ASSERT_THROW(q.pop(), std::out_of_range);
}

TEST(QueueTest, Peek) {
    Queue<int> q;
    ASSERT_TRUE(q.push(1));
    ASSERT_EQ(1, q.peek());
    ASSERT_FALSE(q.is_empty());
}

TEST(QueueTest, ThrowsExeptPeekWhenEmpty) {
    Queue<int> q;
    ASSERT_THROW(q.peek(), std::out_of_range);
}

TEST(QueueTest, MultipleItemsFIFO) {
    Queue<int> q;
    ASSERT_TRUE(q.push(1));
    ASSERT_TRUE(q.push(2));
    ASSERT_TRUE(q.push(3));
    ASSERT_EQ(1, q.pop());
    ASSERT_EQ(2, q.pop());
    ASSERT_EQ(3, q.pop());
    ASSERT_TRUE(q.is_empty());
}