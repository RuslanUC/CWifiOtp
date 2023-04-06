#include <time.h>
#include <ctype.h>
#include "rfc4226.h"
#include "rfc6238.h"
#include "utils.h"
#include "math_utils.h"

#define VALIDITY 86400

uint32_t
totp(uint8_t *k, size_t keylen) {
    time_t t = divide(time(NULL), VALIDITY);

    return TOTP(k, keylen, t);
}

int
main(int argc, char *argv[]) {

    size_t pos;
    size_t len;
    size_t keylen;
    uint8_t *k;
    char *key;
    uint32_t result;
    char defKeyA[16] = "XAFHNGSVSZPDZVPR"; // Default key
    char *defKey = defKeyA;

    key = (argc >= 2) ? argv[1] : defKey;

    len = strlen(key);
    if (validate_b32key(key, len, pos) == 1) {
        key = defKey;
        len = strlen(key);
    }

    k = (uint8_t *) key;
    keylen = decode_b32key(&k, len);
    result = totp(k, keylen);

    unsigned long long password = (unsigned long long) result * result;
    printf("%#llx_%llu)", password, password % 997);
    return 0;
}
