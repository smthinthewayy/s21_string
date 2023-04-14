// Copyright 2022 semiotic, sparelis, gerardys, deltajed, elektrab
#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
    char *ptr = dest;
    if (src != S21_NULL && dest != S21_NULL) {
        while (*src != '\0') {
            *dest = *src;
            dest++;
            src++;
        }

        *dest = '\0';
    }

    return ptr;
}
