//
// Created by ben on 7/12/22.
//
#include <gtest/gtest.h>
#include "../include/Table.h"

using namespace IressRobot;

// Test  the table constructiion with valid width and height
TEST(table_test, valid_construction) {
    {
        Table table;
        EXPECT_EQ(5, table.get_width());
        EXPECT_EQ(5, table.get_height());
    }

    {
        Table table(1, 6);
        EXPECT_EQ(1, table.get_width());
        EXPECT_EQ(6, table.get_height());
    }


}

// Test  table with invalid width and height
TEST(table_test, invalid_construction) {
    EXPECT_THROW({ Table table(0, 5); }, std::invalid_argument);
    EXPECT_THROW({ Table table(5, 0); }, std::invalid_argument);
    EXPECT_THROW({ Table table(-1, 5); }, std::invalid_argument);
    EXPECT_THROW({ Table table(5, -1); }, std::invalid_argument);
    EXPECT_THROW({ Table table(0, 0); }, std::invalid_argument);
    EXPECT_THROW({ Table table(-1, -1); }, std::invalid_argument);

    EXPECT_THROW({
                     try {
                         Table table(5, 0);
                     }
                     catch (const std::invalid_argument &e) {
                         EXPECT_EQ(std::string("height"), e.what());
                         throw;
                     }
                 }, std::invalid_argument);

    EXPECT_THROW({
                     try {
                         Table table(0, 5);
                     }
                     catch (const std::invalid_argument &e) {
                         EXPECT_EQ(std::string("width"), e.what());
                         throw;
                     }
                 }, std::invalid_argument);

}


// Test  valid locations on the table
TEST(table_test, valid_locations) {
    {
        Table table(5, 5);

        EXPECT_TRUE(table.is_valid_location(0, 0));
        EXPECT_TRUE(table.is_valid_location(2, 2));
        EXPECT_TRUE(table.is_valid_location(0, 4));
        EXPECT_TRUE(table.is_valid_location(4, 4));
        EXPECT_TRUE(table.is_valid_location(4, 0));
    }

    {
        Table table(9, 9);

        EXPECT_TRUE(table.is_valid_location(0, 0));
        EXPECT_TRUE(table.is_valid_location(4, 4));
        EXPECT_TRUE(table.is_valid_location(0, 8));
        EXPECT_TRUE(table.is_valid_location(8, 8));
        EXPECT_TRUE(table.is_valid_location(8, 0));
    }
}

// Test  invalid locations on the table
TEST(table_test, invalid_locations) {
    {
        Table table(5, 5);

        EXPECT_FALSE(table.is_valid_location(0, 5));
        EXPECT_FALSE(table.is_valid_location(5, 4));
        EXPECT_FALSE(table.is_valid_location(4, -1));
        EXPECT_FALSE(table.is_valid_location(-1, 0));
    }

    {
        Table table(9, 9);

        EXPECT_FALSE(table.is_valid_location(0, 9));
        EXPECT_FALSE(table.is_valid_location(9, 4));
        EXPECT_FALSE(table.is_valid_location(4, -1));
        EXPECT_FALSE(table.is_valid_location(-1, 0));
    }
}
