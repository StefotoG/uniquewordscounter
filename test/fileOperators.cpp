#include "gtest/gtest.h"

extern "C" {
    #include "fileOperators.h"
}

TEST(countWords, verifyUniqueWords){
    char smallfile[] = "../smalldictionary.txt";
    //smalldictionary.txt is with exactly 35 unique words and should not be changed.
    ASSERT_EQ(fileOperators_countWords(smallfile), 35);
}
TEST(countCyrillicWords, verifyCyrillicWords){
    char cyrillicfile[] = "../cyrillicdictionary.txt";
    //cyrillicdictionary.txt is with exactly 14 unique words and should not be changed.
    ASSERT_EQ(fileOperators_countWords(cyrillicfile), 14);
}
TEST(countMixedWords, verifyMixedWords){
    char mixedfile[] = "../mixeddictionary.txt";
    //mixeddictionary.txt is with exactly 13 unique words and should not be changed.
    ASSERT_EQ(fileOperators_countWords(mixedfile), 13);
}
TEST(notExistingFile, verifyHandlingOfinput){
    char notexistingfile[] = "notexisting";
    EXPECT_EXIT(fileOperators_countWords(notexistingfile), testing::ExitedWithCode(0), "File can't be open!\n");
}   