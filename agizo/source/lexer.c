#include <stdint.h>
#include <stdio.h>
#include "lexer.h"

void agizo_lexer_preprocess(char* str, uint32_t size)
{
    // will iterate over the string like this
    uint32_t c = 0;
    while (c < size)
    {
        printf("lexer : %c\r\n",str[c++]);
    }
}

void agizo_lexer_tokenize(char* str, uint32_t size, char** tokens)
{

}

// keywords:
// ;
// if x > y :
//
// else
//
// end
//
// while x :
