#ifndef _AGIZO_RUNTIME_
#define _AGIZO_RUNTIME_

#define STACK_SIZE_BYTES 128; 

#include <stdint.h>
#include <dtypes.h>



/**
 * Runtime contains the agizo stack
 *
 */


struct AgizoStack
{
    uint8_t top;
    struct DType[];

};

struct RunTime
{
};



#endif
