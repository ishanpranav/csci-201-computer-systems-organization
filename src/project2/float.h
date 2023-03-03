#ifndef FLOAT_H_
#define FLOAT_H_

/**
 * Determines if the given value uses special-value encoding.
 * 
 * This method assumes that the int and float data types have the same size.
 *
 * @param value the floating-point number to test
 * @return a non-zero integer if the given value uses special-value encoding;
 *         otherwise, false.
 */
int is_special(float value);

/*
 * Computes and return the value of M (fractional part) of
 * IEEE single precision floating point number.
 *
 * Parameters:
 *  f - floating point number to extract the mantissa from
 * Return value:
 *  the mantissa of f. If f is a special value, this function should return
 * 0.0 to indicate that f is either +INFINITY or -INFINITY
 * and any other non-zero value to indicate that f is +NAN or -NAN.
 *
 * Assumption sizeof(int) = sizeof(float).
 *
 */
float get_M(float f);

/*
 * Computes and return the value of s (sign) of
 * IEEE single precision floating point number.
 *
 * Parameters:
 *  f - floating point number to extract the sign from
 * Return value:
 *  -1 to indicate negative or +1
 * to indicate positive
 *
 * Assumption sizeof(int) = sizeof(float).
 * The value returned is -1 to indicate negative or +1
 * to indicate positive.
 */
int get_s(float f);

/*
 * Computes and return the value of E (exponent) of
 * IEEE single precision floating point number.
 *
 * Parameters:
 *  f - floating point number to extract the exponent from
 * Return value:
 *  the value of the exponent
 *
 * Assumption sizeof(int) = sizeof(float).
 */
int get_E(float f);

///////////////////////////////////
// Add other declarations below. //
///////////////////////////////////

#endif
