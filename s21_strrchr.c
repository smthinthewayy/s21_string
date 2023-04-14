// Copyright 2022 semiotic, sparelis, gerardys, deltajed, elektrab
#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
    char *result = S21_NULL;
    if (str != S21_NULL) {
        int i = (int) s21_strlen(str);

        while (i >= 0) {
            if (str[i] == (char) c) {
                result = ((char *) (str + i));
                i = 0;
            }
            --i;
        }
    }

    return result;
}
