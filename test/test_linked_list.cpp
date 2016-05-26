//
// Created by Dylan on 26/05/2016.
//

#include "gtest/gtest.h"
#include "linked_list.h"

TEST(LinkedListTest, ConstructorStartEmpty)
{
    LinkedList ll = LinkedList();
    ASSERT_EQ(0, ll.get_size());
}

TEST(LinkedListTest, InsertSingleCheckSize)
{
    LinkedList ll = LinkedList();
    ll.insert(4);
    ASSERT_EQ(1, ll.get_size());
}

TEST(LinkedListTest, InsertMutipleCheckSize)
{
    LinkedList ll = LinkedList();
    ll.insert(4);
    ll.insert(7);
    ASSERT_EQ(2, ll.get_size());
    ll.insert(10);
    ASSERT_EQ(3, ll.get_size());
}

TEST(LinkedListTest, InsertMutipleCheckValues)
{
    LinkedList ll = LinkedList();
    ll.insert(4);
    ASSERT_EQ(4, ll.get(0));
    ll.insert(7);
    ASSERT_EQ(7, ll.get(7));
    ll.insert(10);
    ASSERT_EQ(10, ll.get(10));
}

TEST(LinkedListTest, InsertMutipleCheckIndices)
{
    LinkedList ll = LinkedList();
    ll.insert(4);
    ASSERT_EQ(0, ll.get_index(4));
    ll.insert(7);
    ASSERT_EQ(1, ll.get_index(7));
    ll.insert(10);
    ASSERT_EQ(2, ll.get_index(10));
}

TEST(LinkedListTest, Remove)
{
    LinkedList ll = LinkedList();
    ll.insert(4);
    ll.insert(7);
    ll.insert(10);

    ll.remove(1);
    ASSERT_EQ(1, ll.get_index(10));
    ASSERT_EQ(2, ll.get_size());
}


TEST(LinkedListTest, GetIndexValueNotFound)
{
    LinkedList ll = LinkedList();
    ll.insert(4);
    ll.insert(7);

    ASSERT_EQ(-1, ll.get_index(10));
}