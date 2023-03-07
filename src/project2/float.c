// Author: Ishan Pranav
// Copyright (c) 2023 Ishan Pranav. All rights reserved. 
// Licensed under the MIT License. 

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "float.h"

/**
 * Specifies a 23-bit number with all bits set. This mask yields the mantissa
 * of a 32-bit IEEE single-precision number.
 */
#define MANTISSA_MASK 0x7fffff

/**
 * 
 */
#define EXPONENT_MASK

int is_special(float value)
{
    return 0;
}

float get_M(float value)
{
    assert(sizeof(float) == sizeof(int));

    int buffer;

    memcpy(&buffer, &value, sizeof(value));

    return 0.0;
}

int get_s(float value)
{
    assert(sizeof(float) == sizeof(int));

    return 0;
}

int get_E(float value)
{
    assert(sizeof(float) == sizeof(int));

    return 0;
}
