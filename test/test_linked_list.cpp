//
// Created by Dylan on 26/05/2016.
//

#include "gtest/gtest.h"
#include "linked_list.h"

TEST(LinkedListIntTest, ConstructorStartEmpty) {
    LinkedList<int> ll;
    ASSERT_EQ(0, ll.get_size());
}

TEST(LinkedListIntTest, InsertSingleCheckSize) {
    LinkedList<int> ll;
    ASSERT_TRUE(ll.insert(4));
    ASSERT_EQ(1, ll.get_size());
}

TEST(LinkedListIntTest, InsertGetMutiple) {
    LinkedList<int> ll;

    ASSERT_TRUE(ll.insert(4));
    ASSERT_EQ(4, ll.peek_at(0));
    ASSERT_EQ(1, ll.get_size());
    ASSERT_EQ(4, ll.get(0));
    ASSERT_TRUE(ll.insert(4));

    ASSERT_TRUE(ll.insert(7));
    ASSERT_EQ(2, ll.get_size());

    ASSERT_TRUE(ll.insert(10));
    ASSERT_EQ(3, ll.get_size());
    ASSERT_EQ(10, ll.get(2));
}

TEST(LinkedListIntTest, InsertMutipleCheckIndices) {
    LinkedList<int> ll;
    ll.insert(4);
    ll.insert(7);
    ll.insert(10);

    ASSERT_EQ(0, ll.get_index(4));
    ASSERT_EQ(1, ll.get_index(7));
    ASSERT_EQ(2, ll.get_index(10));
}

TEST(LinkedListIntTest, Remove) {
    LinkedList<int> ll;
    ll.insert(4);
    ll.insert(7);
    ll.insert(10);

    ASSERT_EQ(2, ll.get_index(10));
    ll.remove(1);
    ASSERT_EQ(1, ll.get_index(10));
    ASSERT_EQ(2, ll.get_size());
}


TEST(LinkedListIntTest, GetIndexValueNotFound) {
    LinkedList<int> ll;
    ll.insert(4);
    ll.insert(7);

    ASSERT_EQ(-1, ll.get_index(10));
}

TEST(LinkedListIntTest, RemoveHead) {
    LinkedList<int> ll;
    ll.insert(4);
    ll.insert(7);
    ASSERT_TRUE(ll.remove(0));
    ASSERT_EQ(0, ll.get_index(7));
    ASSERT_EQ(1, ll.get_size());
}

TEST(LinkedListIntTest, RemoveLastElement) {
    LinkedList<int> ll;
    ll.insert(4);
    ll.insert(7);

    ASSERT_TRUE(ll.remove(1));
    ASSERT_EQ(1, ll.get_size());
    ASSERT_TRUE(ll.insert(5));
    ASSERT_EQ(2, ll.get_size());
    ASSERT_EQ(1, ll.get_index(5));
}

TEST(LinkedListIntTest, InsertGetWithOperator) {
    LinkedList<int> ll;
    ASSERT_TRUE(ll.insert(4));
    ASSERT_EQ(4, ll[0]);
}

TEST(LinkedListTypeTest, Float) {
    LinkedList<float> ll;
    ASSERT_TRUE(ll.insert(10));
    ASSERT_EQ(10, ll.peek_at(0));
    ASSERT_EQ(1, ll.get_size());
    ASSERT_TRUE(ll.insert(20));
    ASSERT_TRUE(ll.insert(30));
    ASSERT_EQ(3, ll.get_size());
    ASSERT_EQ(2, ll.get_index(30));
    ASSERT_EQ(20, ll.get(1));
    ASSERT_TRUE(ll.remove(0));
    ASSERT_EQ(0, ll.get_index(30));
}

TEST(LinkedListTypeTest, String) {
    LinkedList<std::string> ll;
    ASSERT_TRUE(ll.insert("10"));
    ASSERT_EQ("10", ll.peek_at(0));
    ASSERT_EQ(1, ll.get_size());
    ASSERT_TRUE(ll.insert("20"));
    ASSERT_TRUE(ll.insert("30"));
    ASSERT_EQ(3, ll.get_size());
    ASSERT_EQ(2, ll.get_index("30"));
    ASSERT_EQ("20", ll.get(1));
    ASSERT_TRUE(ll.remove(0));
    ASSERT_EQ(0, ll.get_index("30"));
}