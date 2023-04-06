#include <stdlib.h>
#include "math_utils.h"

long long divide(long long dividend, long long int divisor) {
    long long sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    dividend = llabs(dividend);
    divisor = llabs(divisor);

    long long quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        ++quotient;
    }

    return quotient * sign;
}

long long getRemainder(long long num, long long divisor) {
    return (num - divisor * (divide(num, divisor)));
}