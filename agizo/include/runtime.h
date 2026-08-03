#ifndef _AGIZO_RUNTIME_
#define _AGIZO_RUNTIME_

#define STACK_SIZE 128 

#include <stdint.h>
#include <dtypes.h>



/**
 * Runtime contains the agizo stack
 *
 */


struct AgizoStack
{
    struct DType stack[STACK_SIZE];
    uint8_t ptr;

};

struct RunTime
{

};



#endif
