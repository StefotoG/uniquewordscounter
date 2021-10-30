#include "gtest/gtest.h"

extern "C" {
    #include "fileOperators.h"
}

TEST(sum, ok){
    ASSERT_EQ(sum(2, 3), 5);
}