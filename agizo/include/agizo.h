#ifndef _AGIZO_RUNTIME_
#define _AGIZO_RUNTIME_

#include <stdint.h>
#include <stdio.h>
#include <dtypes.h>

#define STACK_ALLOC_SIZE 64
#define MAX_FILE_CHARS 255

// Error codes
// ===========
typedef enum
{
    GOOD, //0
    FILE_BOUNDS_EXCEEDED,
    REALLOC_FAILED
} RET_STATE;



// Agizo Stack
// ===========

/*  Agizo Stack 
 *  @brief stack that holds the agizo data
*/
typedef struct agizo_stack
{
    agizo_data stack[STACK_ALLOC_SIZE];
    uint8_t ptr;
    uint8_t size;
    uint8_t top;

} Agizo_Stack;

// pushes data onto the agizo stack
void agizo_stack_push(agizo_data* data);

// pops data from the agizo stack`
void agizo_stack_pop();

// Agizo Runtime & related methods
// ===============================
/*  Agizo Runtime
 *  @brief agizo
*/
typedef struct
{
    Agizo_Stack* agizo_stack;

    uint16_t file_c; // file character count
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

/*@brief executes an open file
*/
uint8_t agizo_execute_file(Agizo_Runtime* r, FILE* fp);

/*@brief executes a string
*/
uint8_t agizo_execute_string(Agizo_Runtime* r, char* string);

#endif
