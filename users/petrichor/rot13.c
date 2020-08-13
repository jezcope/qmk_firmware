#include "rot13.h"

char rot_char(char c) {
    if (c >= 'a' && c <= 'm') {
        return c += 13;
    } else if (c >= 'n' && c <= 'z') {
        return c -= 13;
    } else if (c >= 'A' && c <= 'M') {
        return c += 13;
    } else if (c >= 'N' && c <= 'Z') {
        return c -= 13;
    }

    return c;
}

void rot13(char* s) {
    for (; *s != 0; s++) {
        *s = rot_char(*s);
    }
}
