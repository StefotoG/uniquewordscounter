#include "gtest/gtest.h"

extern "C" {
    #include "fileOperators.h"
}

TEST(countWords, verifyUniqueWords){
    char file[] = "../../smalldictionary.txt";
    //smalldictionary.txt is with exactly 35 unique words and should not be changed.
    ASSERT_EQ(fileOperators_countWords(file), 35);

}