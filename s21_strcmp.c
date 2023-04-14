// Copyright 2022 semiotic, sparelis, gerardys, deltajed, elektrab
#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
    const unsigned char *c1 = (const unsigned char *) str1;
    const unsigned char *c2 = (const unsigned char *) str2;

    while (*c1 && *c1 == *c2) ++c1, ++c2;

    return *(const unsigned char *) c1 - *(const unsigned char *) c2;
}
