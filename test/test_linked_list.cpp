//
// Created by Dylan on 26/05/2016.
//

#include "gtest/gtest.h"
#include "linked_list.h"

TEST(LinkedListTest, ConstructorStartEmpty) {
    LinkedList ll = LinkedList();
    ASSERT_EQ(0, ll.get_size());
}

TEST(LinkedListTest, InsertSingleCheckSize) {
    LinkedList ll = LinkedList();
    ASSERT_TRUE(ll.insert(4));
    ASSERT_EQ(1, ll.get_size());
}

TEST(LinkedListTest, InsertGetMutiple) {
    LinkedList ll = LinkedList();

    ASSERT_TRUE(ll.insert(4));
    ASSERT_EQ(4, ll.get(0));
    ASSERT_EQ(1, ll.get_size());

    ASSERT_TRUE(ll.insert(7));
    ASSERT_EQ(7, ll.get(1));
    ASSERT_EQ(2, ll.get_size());

    ASSERT_TRUE(ll.insert(10));
    ASSERT_EQ(10, ll.get(2));
    ASSERT_EQ(3, ll.get_size());
}

TEST(LinkedListTest, InsertMutipleCheckIndices) {
    LinkedList ll = LinkedList();
    ll.insert(4);
    ll.insert(7);
    ll.insert(10);

    ASSERT_EQ(0, ll.get_index(4));
    ASSERT_EQ(1, ll.get_index(7));
    ASSERT_EQ(2, ll.get_index(10));
}

TEST(LinkedListTest, Remove) {
    LinkedList ll = LinkedList();
    ll.insert(4);
    ll.insert(7);
    ll.insert(10);

    ASSERT_EQ(2, ll.get_index(10));
    ll.remove(1);
    ASSERT_EQ(1, ll.get_index(10));
    ASSERT_EQ(2, ll.get_size());
}


TEST(LinkedListTest, GetIndexValueNotFound) {
    LinkedList ll = LinkedList();
    ll.insert(4);
    ll.insert(7);

    ASSERT_EQ(-1, ll.get_index(10));
}

TEST(LinkedListTest, RemoveHead) {
    LinkedList ll = LinkedList();
    ll.insert(4);
    ll.insert(7);
    ASSERT_TRUE(ll.remove(0));
    ASSERT_EQ(0, ll.get_index(7));
    ASSERT_EQ(1, ll.get_size());
}

TEST(LinkedListTest, RemoveLastElement) {
    LinkedList ll = LinkedList();
    ll.insert(4);
    ll.insert(7);

    ASSERT_TRUE(ll.remove(1));
    ASSERT_EQ(1, ll.get_size());
    ASSERT_TRUE(ll.insert(5));
    ASSERT_EQ(2, ll.get_size());
    ASSERT_EQ(1, ll.get_index(5));
}

TEST(LinkedListTest, InsertGetWithOperator) {
    LinkedList ll = LinkedList();
    ASSERT_TRUE(ll.insert(4));
    ASSERT_EQ(4, ll[0]);
}