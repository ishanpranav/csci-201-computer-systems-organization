// Author: Ishan Pranav
// Copyright (c) 2023 Ishan Pranav. All rights reserved.
// Licensed under the MIT License.

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "float.h"

int is_special(float value)
{
    return 0;
}

float get_M(float value)
{
    unsigned int mantissa = *((unsigned int *)&value) & 0x7fffffu;

    mantissa |= 0x3f800000u;

    return *((float*)&mantissa);
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
    return 0;
}
