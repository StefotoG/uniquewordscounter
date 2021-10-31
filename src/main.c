#include <stdio.h>
#include "fileOperators.h"

#define EXPECTED_NUMBER_OF_ARGUMENTS 2
#define FILE_NAME 1

int main(int argc, char **argv)
{

    if (argc > EXPECTED_NUMBER_OF_ARGUMENTS || argc < EXPECTED_NUMBER_OF_ARGUMENTS)
    {
        printf("Wrong number of arguments! Expected only two but were passed: %d\n", argc);
    }
    else
    {
        fileOperators_countWords(argv[FILE_NAME]);
    }

    sum(2, 3);
    return 0;
}