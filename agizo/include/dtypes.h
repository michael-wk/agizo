#ifndef _DTYPES_
#define _DTYPES_

#include <stdint.h>

/*
 * DTypes defines data types (and instruction types) that exist in
 * agizo
 */


// _type enum represents the agizo type that the data represents
//
// number
// string
// var

typedef enum
{
    NUMBER,
    STRING,
    NFUNC
} agizo_data_type;

typedef struct
{
    int32_t value;
    uint8_t sign;
    agizo_data_type type;

} agizo_data;


#endif
