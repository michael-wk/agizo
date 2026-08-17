

#include <stdio.h>
#include <stdlib.h>
#include "agizo.h"
#include "lexer.h"
#include "dtypes.h"


void agizo_runtime_init(Agizo_Runtime* runtime, Agizo_Stack* a_stack)
{
    runtime->agizo_stack = a_stack;
    runtime->agizo_stack->size = STACK_ALLOC_SIZE;
    runtime->agizo_stack->ptr = 0;
    runtime->agizo_stack->top = 0;
}



void agizo_runtime_debug(Agizo_Runtime* runtime)
{
    printf("\r\n______________\r\nruntime debug:\r\nstack size  :   %d\r\nstack ptr   :   %d\r\nstack top   :   %d\r\n",
            runtime->agizo_stack->size, runtime->agizo_stack->ptr, runtime->agizo_stack->top);
}



uint8_t agizo_execute_file(Agizo_Runtime* r, FILE* fp)
{
   
    printf("______________\r\n");
    printf("executing file:\r\n");
    r->file_c = 0;
    char* s = malloc(sizeof(char) * MAX_FILE_CHARS);
    int ch;
    
    // populating string with file content
    while ((ch = getc(fp)) != EOF)
    {
        if (r->file_c == MAX_FILE_CHARS -1)
        {
            free(s);
            return FILE_BOUNDS_EXCEEDED;
        }
        s[r->file_c++] = ch;
    }
    s[r->file_c++] = '\0'; // null terminating string
   
    //printf("file");
    // reallocating string to actual size within bounds
    //char* tmp;
    //tmp = realloc(s, sizeof(char)*r->file_c);
    
    //if (tmp == NULL)
    //{
    //    free(s);
    //    return REALLOC_FAILED;
    //} else
    //{
    //    s = tmp;
    //}

    RET_STATE res = agizo_execute_string(r, s);
    free(s);
    return GOOD;
}

uint8_t agizo_execute_string(Agizo_Runtime* runtime, char* content)
{
    agizo_lexer_preprocess(content, runtime->file_c);

    return GOOD;
}


