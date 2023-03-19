// Author: Ishan Pranav
// Copyright (c) 2023 Ishan Pranav. All rights reserved.
// Licensed under the MIT License.

#include "float.h"

/**
 * 
*/
typedef enum exponent
{
    /**
     * 
    */
    EXPONENT_DENORMALIZED = 0,

    /**
     * 
    */
    EXPONENT_SPECIAL = 255
} exponent;

/**
 * 
*/
static exponent get_exponent(float value)
{
    return ((*((unsigned int *)&value) & 0x7f800000) >> 23);
}

int is_special(float value)
{
    return get_exponent(value) == EXPONENT_SPECIAL;
}

float get_M(float value)
{
    unsigned int mantissa = (*((unsigned int *)&value) & 0x7fffff) | 0x3f800000u;
    float result = *((float *)&mantissa);
    
    switch (get_exponent(value))
    {
    case EXPONENT_DENORMALIZED:
    case EXPONENT_SPECIAL:
        return result - 1;

    default:
        return result;
    }
}

int get_s(float value)
{
    if (value < 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int get_E(float value)
{
    exponent exponent = get_exponent(value);

    switch (exponent)
    {
    case EXPONENT_DENORMALIZED:
        return -126;

    case EXPONENT_SPECIAL:
        return EXPONENT_SPECIAL;

    default:
        return exponent - 127;
    }
}
