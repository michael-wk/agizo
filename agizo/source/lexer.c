#include <stdint.h>
#include <stdio.h>
#include "lexer.h"

void agizo_lexer_preprocess(char* str, uint32_t size)
{
    // will iterate over the string like this
    uint16_t c = 0;
    printf("______________\r\nlexer:\r\n");
    while (c < size)
    {
        printf("%c",str[c++]);
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
