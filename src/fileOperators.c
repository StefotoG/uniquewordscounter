#include "fileOperators.h"

#include <string.h>

#define MAX_WORD_SIZE 128
#define NOT_UNIQUE 0
#define UNIQUE 1
#define SUCCESS 1

const char delimit[] = " \t\r\n\v\f,.(!)?";

int _fileOperators_isWordUnique(char *token, FILE *tempFile)
{
    char word[MAX_WORD_SIZE];

    /*iterates from the file pointer to the end of the file searching
    for a second ocurrence for token.*/
    while (fscanf(tempFile, "%127s", word) == SUCCESS)
    {
        //strtok is not safe and has shortcomings
        char *localtoken = strtok(word, delimit);

        //strcmp returns 0 if strings are equal
        if (!strcmp(token, localtoken))
            return NOT_UNIQUE;
    }
    return UNIQUE;
}

int _fileOperators_countUnique(FILE *fp, FILE *tempFile)
{
    int uniqueWords = 0;
    char word[MAX_WORD_SIZE];

    //reads the file word by word
    while (fscanf(fp, "%127s", word) == SUCCESS)
    {
        /*strtok is not safe and has shortcomings. Removes any special
        characters from the word(ex: hello? transforms to hello)*/
        char *token = strtok(word, delimit);

        //shifts the second file pointer to the next word in file
        fseek(tempFile, ftell(fp), SEEK_SET);
        uniqueWords += _fileOperators_isWordUnique(token, tempFile);
    }
    return uniqueWords;
}

int fileOperators_countWords(char *filename)
{
    printf("filename is: %s\n", filename);

    FILE *fp = fopen(filename, "r");
    FILE *tempFile = fopen(filename, "r");

    int totalWords = 0;

    if (fp == NULL || tempFile == NULL)
    {
        printf("File can't be open!\n");
        return 1;
    }
    else
    {
        totalWords = _fileOperators_countUnique(fp, tempFile);
        printf("unique words are: %d\n", totalWords);
    }

    fclose(tempFile);
    fclose(fp);
    return totalWords;
}