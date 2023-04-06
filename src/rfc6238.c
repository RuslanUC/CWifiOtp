#include "rfc6238.h"


uint32_t
TOTP(uint8_t *key, size_t kl, uint64_t time) {
    uint32_t totp;

    totp = HOTP(key, kl, time);
    return totp;
}
