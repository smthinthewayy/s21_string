// Copyright 2022 semiotic, sparelis, gerardys, deltajed, elektrab
#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
    s21_size_t length = 0;
    if (str != S21_NULL) {
        while (*str != '\0') {
            length++;
            str++;
        }
    }

    return length;
}
