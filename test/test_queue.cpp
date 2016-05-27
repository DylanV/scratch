//
// Created by Dylan Verrezen on 2016/05/27.
//

#include "gtest/gtest.h"
#include "queue.h"

TEST(QueueTest, ConstructorStartEmpty) {
    Queue<int> s;
    ASSERT_TRUE(s.is_empty());
    ASSERT_EQ(0, s.get_size());
}

TEST(QueueTest, AddSingleElement) {
    Queue<int> s;
    ASSERT_TRUE(s.push(1));
    ASSERT_EQ(1, s.get_size());
    ASSERT_FALSE(s.is_empty());
}

TEST(QueueTest, AddAndGetSingle) {
    Queue<int> s;
    ASSERT_TRUE(s.push(1));
    ASSERT_EQ(1, s.pop());
    ASSERT_TRUE(s.is_empty());
    ASSERT_EQ(0, s.get_size());
}

TEST(QueueTest, ThrowsExeptPopWhenEmpty) {
    Queue<int> s;
    ASSERT_THROW(s.pop(), std::out_of_range);
}

TEST(QueueTest, Peek) {
    Queue<int> s;
    ASSERT_TRUE(s.push(1));
    ASSERT_EQ(1, s.peek());
    ASSERT_FALSE(s.is_empty());
}

TEST(QueueTest, ThrowsExeptPeekWhenEmpty) {
    Queue<int> s;
    ASSERT_THROW(s.peek(), std::out_of_range);
}

TEST(QueueTest, MultipleItemsFIFO) {
    Queue<int> s;
    ASSERT_TRUE(s.push(1));
    ASSERT_TRUE(s.push(2));
    ASSERT_TRUE(s.push(3));
    ASSERT_EQ(1, s.pop());
    ASSERT_EQ(2, s.pop());
    ASSERT_EQ(3, s.pop());
    ASSERT_TRUE(s.is_empty());
}