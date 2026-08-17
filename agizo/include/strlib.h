#ifndef _STR_LIB_
#define _STR_LIB_

#include <stdint.h>

/* string shift
 * @brief char pointer buffer, starting at idx, direction
 * elements across.
 * does not reallocate the size of the buffer
 *
 * @warn shifted values that overflow the buffer bounds
 * are discarded
*/ 
void _strshf(char* str, uint16_t idx, int16_t dir, uint16_t buf_size);



#endif
