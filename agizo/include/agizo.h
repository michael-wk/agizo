#ifndef _AGIZO_RUNTIME_
#define _AGIZO_RUNTIME_

#include <stdint.h>
#include <dtypes.h>

#define STACK_ALLOC_SIZE 64

// Agizo Stack
// ===========

/*  Agizo Stack 
 *  @brief stack that holds the agizo data
*/
typedef struct agizo_stack
{
    struct DType* stack;
    uint8_t ptr;
    uint8_t size;
    uint8_t top;

} Agizo_Stack;


// Agizo Runtime & related methods
// ===============================

/*  Agizo Runtime
 *  @brief agizo
*/
typedef struct
{
    Agizo_Stack* agizo_stack;
} Agizo_Runtime; 

/*  Runtime Init
 *  @brief initializes runtime;
*/
void agizo_runtime_init(Agizo_Runtime* runtime, Agizo_Stack* a_stack);

/*  Runtime Debug
 *  @brief outputs runtime data to a debugging console using printf
 *  @warn requires printf to be implemented to output.
 */
void agizo_runtime_debug(Agizo_Runtime*);




#endif
