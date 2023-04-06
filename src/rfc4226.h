#ifndef RFC4226_H
#define RFC4226_H

#include <stdint.h>
#include <stdlib.h>

uint32_t HOTP(uint8_t *key, size_t kl, uint64_t interval);

uint8_t *hmac(unsigned char *key, int kl, uint64_t interval);

uint32_t DT(uint8_t *digest);

#endif
