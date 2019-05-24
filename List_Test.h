//
// Created by a27stude on 19.03.19.
//

#ifndef CODINGDOJO_LIST_TEST_H
#define CODINGDOJO_LIST_TEST_H

#include <gtest/gtest.h>
#include "List.h"

class List_Test : public testing::Test {

public:
    List uut;
};

TEST_F(List_Test, adding_to_list_OK) {
    ASSERT_TRUE(uut.empty());
    uut.push_back(7);
    ASSERT_TRUE(!uut.empty());
    ASSERT_EQ(1, uut.get_size());
    uut.push_back(666);
    ASSERT_EQ(2, uut.get_size());
}

TEST_F(List_Test, deleting_from_list_OK) {
    uut.push_back(666);
    uut.push_back(997);
    uut.push_back(420);

    ASSERT_EQ(3, uut.get_size());

    uut.pop_back();
    ASSERT_EQ(2, uut.get_size());

    uut.pop_back();
    ASSERT_EQ(1, uut.get_size());

    uut.pop_back();
    ASSERT_TRUE(uut.empty());
}

TEST_F (List_Test, deleting_one_element_OK) {

    uut.push_back(8);
    uut.pop_back();
    ASSERT_TRUE(uut.empty());
}

TEST_F(List_Test, deleting_from_empty_list_OK){
   ASSERT_THROW(uut.pop_back(),std::runtime_error);
}

TEST_F(List_Test, getting_last_element_OK) {
    uut.push_back(666);
    uut.push_back(997);
    uut.push_back(420);
    ASSERT_EQ(420, uut.back());


}

TEST_F(List_Test, getting_element_from_empty_list_throws_exception) {

    ASSERT_THROW(uut.back(), std::runtime_error);

}

TEST_F(List_Test, reverse_list_OK) {
    uut.push_back(666);
    uut.push_back(997);
    uut.push_back(420);
    uut.reverse();
    ASSERT_EQ(3, uut.get_size());
    ASSERT_EQ(uut.back(), 666);
    uut.pop_back();
    ASSERT_EQ(uut.back(), 997);
    uut.pop_back();
    ASSERT_EQ(uut.back(), 420);
    uut.pop_back();

}

TEST_F(List_Test, sort_list_OK) {
    uut.push_back(666);
    uut.push_back(997);
    uut.push_back(420);
    uut.sort();
    ASSERT_EQ(3, uut.get_size());
    ASSERT_EQ(uut.back(), 997);
    uut.pop_back();
    ASSERT_EQ(uut.back(), 666);
    uut.pop_back();
    ASSERT_EQ(uut.back(), 420);
    uut.pop_back();

}

TEST_F(List_Test, countAllValues3ElOK) {
    uut.push_back(666);
    uut.push_back(997);
    uut.push_back(420);

    ASSERT_EQ(uut.countAllValues(), 666+997+420);
}

TEST_F(List_Test, countAllValues1ElOK) {
    uut.push_back(-2137);

    ASSERT_EQ(uut.countAllValues(), -2137);
}

TEST_F(List_Test, is_string_OK){
    uut.push_back(666);
    uut.push_back(997);
    uut.push_back(420);

    EXPECT_EQ("Zawartosc listy: 666, 997, 420", uut.print());
}

TEST_F(List_Test, is_empty_string_OK){


    EXPECT_EQ("Zawartosc listy: PUSTA", uut.print());
}

#endif //CODINGDOJO_LIST_TEST_H
