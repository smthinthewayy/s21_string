// Copyright 2022 semiotic, sparelis, gerardys, deltajed, elektrab
#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int flag = 0;
    int result = 0;
    if (n == 0) {
        flag = 1;
        result = 0;
    }

    if (!flag) {
        s21_size_t i = 0;
        while (*(str1 + i) && *(str2 + i) && i < n - 1 && *(str1 + i) == *(str2 + i))
            i++;
        if (*(str1 + i) != *(str2 + i))
            result = *(unsigned char *) (str1 + i) - *(unsigned char *) (str2 + i);
    }

    return result;
}
