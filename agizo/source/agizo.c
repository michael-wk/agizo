#include <stdio.h>
#include "agizo.h"
#include "dtypes.h"



void agizo_runtime_init(Agizo_Runtime* runtime, Agizo_Stack* a_stack)
{
    runtime->agizo_stack->size = STACK_ALLOC_SIZE;
    runtime->agizo_stack->ptr = 0;
    runtime->agizo_stack->top = 0;

    struct DType* s[STACK_ALLOC_SIZE];
    a_stack->stack = s; 
    runtime->agizo_stack = a_stack;


}


void agizo_runtime_debug(Agizo_Runtime* runtime)
{
    printf("\r\n______________\r\nruntime debug:\r\nstack size  :   %d\r\nstack ptr   :   %d\r\nstack top   :   %d\r\n",
            runtime->agizo_stack->size, runtime->agizo_stack->ptr, runtime->agizo_stack->top);
}

