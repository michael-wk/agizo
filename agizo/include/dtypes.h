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

enum _type
{
    number,
    string,
};

struct DType
{
    int32_t value;
    uint8_t sign;
    // something that represents what actually is the datatype of this thing
    // an enum? w
    enum _type type;

};


#endif
