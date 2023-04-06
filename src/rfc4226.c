#include <stdint.h>
#include <math.h>
#include <malloc.h>
#include "hmac.h"
#include "math_utils.h"

uint8_t* hmac(unsigned char *key, int kl, uint64_t interval) {
    uint8_t *output = malloc(20);

    hmac_sha1(key, kl, (const unsigned char *) &interval, sizeof(interval), output);

    return output;
}

uint32_t DT(uint8_t *digest) {

    uint64_t offset;
    uint32_t bin_code;

    // dynamically truncates hash
    offset = digest[19] & 0x0f;

    bin_code = (digest[offset] & 0x7f) << 24
               | (digest[offset + 1] & 0xff) << 16
               | (digest[offset + 2] & 0xff) << 8
               | (digest[offset + 3] & 0xff);

    // truncates code to 6 digits

    return bin_code;

}


uint32_t mod_hotp(uint32_t bin_code) {
    int power = 1000000; // 6 digits
    uint32_t otp = (uint32_t)getRemainder((long long)bin_code, (long long)power);

    return otp;
}


uint32_t HOTP(uint8_t *key, size_t kl, uint64_t interval) {

    uint8_t *digest;
    uint32_t result;
    uint32_t endianness;

    endianness = 0xdeadbeef;
    if ((*(const uint8_t *) &endianness) == 0xef) {
        interval = ((interval & 0x00000000ffffffff) << 32) | ((interval & 0xffffffff00000000) >> 32);
        interval = ((interval & 0x0000ffff0000ffff) << 16) | ((interval & 0xffff0000ffff0000) >> 16);
        interval = ((interval & 0x00ff00ff00ff00ff) << 8) | ((interval & 0xff00ff00ff00ff00) >> 8);
    };

    //First Phase, get the digest of the message using the provided key ...

    digest = (uint8_t *) hmac(key, kl, interval);
    //Second Phase, get the dbc from the algorithm
    uint32_t dbc = DT(digest);
    //Third Phase: calculate the mod_k of the dbc to get the correct number
    result = mod_hotp(dbc);

    return result;

}
