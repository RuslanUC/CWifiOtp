#ifndef RFC6238_H
#define RFC6238_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "rfc4226.h"


/******** RFC6238 **********
 *
 * TOTP = HOTP(k,T) where
 * K = the supersecret key
 * T = ( Current Unix time - T0) / X
 * where X is the Time Step
 *
 * *************************/


uint32_t TOTP(uint8_t *key, size_t kl, uint64_t time);

#endif
