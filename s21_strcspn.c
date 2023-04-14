// Copyright 2022 semiotic, sparelis, gerardys, deltajed, elektrab
#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t len_str1 = s21_strlen(str1);
    s21_size_t len_str2 = s21_strlen(str2);

    int supp = 0;
    s21_size_t i = 0;
    s21_size_t count = 0;
    for (; i < len_str1; i++) {
        if (supp)
            break;

        for (s21_size_t j = 0; j < len_str2; j++) {
            if (str1[i] == str2[j]) {
                count = i;
                supp++;
                break;
            }
        }
    }

    if (!supp)
        count = i;

    return count;
}
