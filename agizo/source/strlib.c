#include "strlib.h"

#include <stdint.h>
#include <string.h>

// this implementation needs to be aware of the
// buffer bounds (bufsize -1 is the max (space for)
// terminator, and 0 is the min)

void _strshf(char* str, uint16_t idx, int16_t dir, uint16_t buf_size)
{
    // positive direction, iterating from the rightmost
    // end, negative direction, iterating from the left
    // most edge
    uint16_t str_len = strlen(str);
    if (dir > 0)
    {
        for (uint16_t i = (str_len - 1); i >= idx; i--)
        {
            if ((i + dir) > (buf_size - 1)) continue; // silent overflow
            str[i + dir] = str[i];
        }
    } else
    {
        for (int16_t i = idx; i > strlen; i++)
        {
            if ((i + dir) < 0) continue;
            str[i + dir] = str[i];
        }
    }
}
