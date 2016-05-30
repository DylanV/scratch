//
// Created by Dylan Verrezen on 2016/05/27.
//

#include "gtest/gtest.h"
#include "double_linked_list.h"

TEST(DoubleLinkedListTest, ConstructorStartEmpty) {
    DoubleLinkedList<int> dll;
    ASSERT_EQ(0, dll.get_size());
}

TEST(DoubleLinkedListTest, InsertitemSizeincrease) {
    DoubleLinkedList<int> dll;
    ASSERT_TRUE(dll.insert(1));
    ASSERT_EQ(1, dll.get_size());
}

TEST(DoubleLinkedListTest, InsertMultiple) {
    DoubleLinkedList<int> dll;
    ASSERT_TRUE(dll.insert(1));
    ASSERT_TRUE(dll.insert(2));
    ASSERT_TRUE(dll.insert(3));
    ASSERT_EQ(3, dll.get_size());
}

TEST(DoubleLinkedListTest, Peek) {
    DoubleLinkedList<int> dll;
    ASSERT_TRUE(dll.insert(1));
    ASSERT_TRUE(dll.insert(2));
    ASSERT_TRUE(dll.insert(3));
    ASSERT_EQ(1, dll.peek());
    ASSERT_EQ(2, dll.peek_at(1));
    ASSERT_EQ(3, dll.peek_at(2));
}

TEST(DoubleLinkedListTest, IndexOf) {
    DoubleLinkedList<int> dll;
    ASSERT_TRUE(dll.insert(1));
    ASSERT_TRUE(dll.insert(1));
    ASSERT_TRUE(dll.insert(2));
    ASSERT_EQ(0, dll.index_of(1));
    ASSERT_EQ(2, dll.index_of(2));
    ASSERT_EQ(INT_MAX, dll.index_of(6)); //Error
}

TEST(DoubleLinkedListTest, LastIndexOf) {
    DoubleLinkedList<int> dll;
    ASSERT_TRUE(dll.insert(1));
    ASSERT_TRUE(dll.insert(1));
    ASSERT_TRUE(dll.insert(2));
    ASSERT_TRUE(dll.insert(3));

    ASSERT_EQ(1, dll.last_index_of(1));
    ASSERT_EQ(2, dll.last_index_of(2));
    ASSERT_EQ(INT_MAX, dll.last_index_of(6)); //Error
}

TEST(DoubleLinkedListTest, RemoveMiddle) {
    DoubleLinkedList<int> dll;
    ASSERT_TRUE(dll.insert(1));
    ASSERT_TRUE(dll.insert(2));
    ASSERT_TRUE(dll.insert(3));
    ASSERT_TRUE(dll.remove(1));
    ASSERT_EQ(2, dll.get_size());
    ASSERT_EQ(INT_MAX, dll.index_of(2));
}

TEST(DoubleLinkedListTest, RemoveTailAndFindLastOf) {
    DoubleLinkedList<int> dll;
    ASSERT_TRUE(dll.insert(1));
    ASSERT_TRUE(dll.insert(2));
    ASSERT_TRUE(dll.insert(3));
    ASSERT_TRUE(dll.insert(4));

    ASSERT_TRUE(dll.remove(3));
    ASSERT_EQ(2, dll.last_index_of(3));
    ASSERT_EQ(3, dll.get_size());
    ASSERT_EQ(INT_MAX, dll.index_of(4));
}

TEST(DoubleLinkedListTest, RemoveHeadAndFindIndexOf) {
    DoubleLinkedList<int> dll;
    ASSERT_TRUE(dll.insert(1));
    ASSERT_TRUE(dll.insert(2));
    ASSERT_TRUE(dll.insert(3));
    ASSERT_TRUE(dll.insert(4));

    ASSERT_TRUE(dll.remove(0));
    ASSERT_EQ(1, dll.index_of(3));
    ASSERT_EQ(3, dll.get_size());
    ASSERT_EQ(INT_MAX, dll.index_of(1));
}

TEST(DoubleLinkedListTest, RemoveHeadWhenOnly1Item){
    DoubleLinkedList<int> dll;
    ASSERT_TRUE(dll.insert(1));

    ASSERT_TRUE(dll.remove(0));
    ASSERT_EQ(INT_MAX, dll.index_of(1));
    ASSERT_EQ(0, dll.get_size());
}

TEST(DoubleLinkedListTest, GetAtAndGet) {
    DoubleLinkedList<int> dll;
    ASSERT_TRUE(dll.insert(1));
    ASSERT_TRUE(dll.insert(2));
    ASSERT_EQ(2, dll.get_at(1));
    ASSERT_EQ(1, dll.get_size());
    ASSERT_EQ(1, dll.get());
    ASSERT_EQ(0, dll.get_size());
    ASSERT_THROW(dll.get(), std::out_of_range);
}