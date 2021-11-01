#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "fileOperators.h"

#define EXPECTED_NUMBER_OF_ARGUMENTS 2
#define FILE_NAME 1

int main(int argc, char **argv)
{
    
    //cyrillic support
    system("chcp 1251");
    setlocale(LC_ALL, "UTF8");
    //****************

    if (argc > EXPECTED_NUMBER_OF_ARGUMENTS || argc < EXPECTED_NUMBER_OF_ARGUMENTS)
    {
        perror("Wrong number of arguments! Expected only two but were passed: %d\n", argc);
    }
    else
    {
        fileOperators_countWords(argv[FILE_NAME]);
    }

    return 0;
}