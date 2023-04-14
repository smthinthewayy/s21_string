// Copyright 2022 semiotic, sparelis, gerardys, deltajed, elektrab
#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
    s21_memcpy(dest + s21_strlen(dest), src, n);

    return dest;
}
