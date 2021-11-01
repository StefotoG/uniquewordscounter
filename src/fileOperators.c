#include "fileOperators.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE (8 * 1024 * 1024)
#define MAX_WORD_SIZE 128
#define NOT_UNIQUE 0
#define UNIQUE 1
#define SUCCESS 1

const char delimit[] = " \t\r\n\v\f,.(!)?";
unsigned char *bufferedReading;

int _fileOperators_isWordUnique(char *token, FILE *tempFile)
{
    char word[MAX_WORD_SIZE];

    /*
    Iterate over the buffer searching for the token. If no token is found
    allocate a new buffer and search in it. Continue until EOF.
    TODO: Can I optimise tokenising?
    */
    while (fread(bufferedReading, sizeof(unsigned char), BUFFER_SIZE, tempFile))
    {
        //strtok is not safe and has shortcomings
        char *localtoken = strtok(bufferedReading, delimit);
        // printf("localtoken: %s\n token: %s\n", localtoken, token);
        while (localtoken != NULL)
        {
            if (!strcmp(token, localtoken))
            {
                return NOT_UNIQUE;
            }
            localtoken = strtok(NULL, delimit);
        }
    }
    return UNIQUE;
}

int _fileOperators_countUnique(FILE *fp, FILE *tempFile)
{
    int uniqueWords = 0;
    char word[MAX_WORD_SIZE];

    //reads the file word by word
    //TODO: check for alternative of fscanf
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

    //start two pointers for the same file
    FILE *fp = fopen(filename, "r");
    FILE *tempFile = fopen(filename, "r");

    int totalWords = 0;

    if (fp == NULL || tempFile == NULL)
    {
        perror("File can't be open!\n");
        exit(0);
    }
    else
    {
        //allocate 8MiB buffer for faster iterating over the words
        bufferedReading = (unsigned char *)calloc(BUFFER_SIZE, sizeof(unsigned char));

        if (bufferedReading == NULL)
        {
            perror("mem not allocated!\n");
            exit(0);
        }

        totalWords = _fileOperators_countUnique(fp, tempFile);
        printf("unique words are: %d\n", totalWords);
    }
    free(bufferedReading);
    fclose(tempFile);
    fclose(fp);
    return totalWords;
}