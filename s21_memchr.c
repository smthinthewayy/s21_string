// Copyright 2022 semiotic, sparelis, gerardys, deltajed, elektrab
#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
    s21_size_t i = 0;
    const char *s = (const char *) str;

    void *result = S21_NULL;
    while (i < n) {
        if (*(unsigned char *) (s + i) == (unsigned char) c) {
            result = (void *) (s + i);
            break;
        }
        i++;
    }

    return result;
}
