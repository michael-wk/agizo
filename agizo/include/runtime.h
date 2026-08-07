#ifndef _AGIZO_RUNTIME_
#define _AGIZO_RUNTIME_

#define STACK_SIZE 128 

#include <stdint.h>
#include <dtypes.h>



/**
 * Runtime contains the agizo stack
 *
 */


typedef struct agizo_stack
{
    struct DType stack[STACK_SIZE];
    uint8_t ptr;

} AgizoStack;

//struct RunTime
//{
//
//};



#endif
