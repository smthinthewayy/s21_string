// Copyright 2022 semiotic, sparelis, gerardys, deltajed, elektrab
#include "s21_string.h"

#include <check.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

char buf_for_sprintf[70];
char buf_for_s21_sprintf[70];

START_TEST(s21_memchr_test) {
  const char *first;
  const char *second;

  // TEST 1
  first = s21_memchr("Hello world\0", 'w', 5);
  second = memchr("Hello world\0", 'w', 5);

  ck_assert_ptr_eq(first, second);

  // TEST 2
  first = s21_memchr("Hello world\n\0", 'w', 10);
  second = memchr("Hello world\n\0", 'w', 10);

  ck_assert_ptr_eq(first, second);

  // TEST 3
  first = s21_memchr("a\n\0", '\n', 12);
  second = memchr("a\n\0", '\n', 12);

  ck_assert_ptr_eq(first, second);

  // TEST 4
  first = s21_memchr(" \n\0", '\0', 100);
  second = memchr(" \n\0", '\0', 100);

  ck_assert_ptr_eq(first, second);

  // TEST 5
  first = s21_memchr(" \0", ' ', 0);
  second = memchr(" \0", ' ', 0);

  ck_assert_ptr_eq(first, second);

  // // TEST 6
  // first = s21_memchr("\n\0", 'q', 5);
  // second = memchr("\n\0", 'q', 5);

  ck_assert_ptr_eq(first, second);

  // TEST 7
  first = s21_memchr("\0", '\0', 1);
  second = memchr("\0", '\0', 1);

  ck_assert_ptr_eq(first, second);
}

END_TEST

START_TEST(s21_memcmp_test) {
  int first;
  int second;

  // TEST 1
  char *f1 = "Hello world\0";
  char *s1 = "Hello world\0";
  first = s21_memcmp(f1, s1, 5);
  second = memcmp(f1, s1, 5);

  ck_assert_int_eq(first, second);

  // TEST 2
  char *f2 = "Hello world\n\0";
  char *s2 = "Hello world\n\0";
  first = s21_memcmp(f2, s2, 13);
  second = memcmp(f2, s2, 13);

  ck_assert_int_eq(first, second);

  // TEST 3
  char *f3 = "a\n\0";
  char *s3 = "Hello world\n\0";
  first = s21_memcmp(f3, s3, 3);
  second = memcmp(f3, s3, 3);

  ck_assert_int_gt(first, 0);
  ck_assert_int_gt(second, 0);

  // TEST 4
  char *f4 = "H\n\0";
  char *s4 = "a\n\0";
  first = s21_memcmp(f4, s4, 1);
  second = memcmp(f4, s4, 1);

  ck_assert_int_lt(first, 0);
  ck_assert_int_lt(second, 0);

  // TEST 5
  char *f5 = " \n\0";
  char *s5 = " \0";
  first = s21_memcmp(f5, s5, 1);
  second = memcmp(f5, s5, 1);

  ck_assert_int_eq(first, second);

  // TEST 6
  char *f6 = " \0";
  char *s6 = "\n\0";
  first = s21_memcmp(f6, s6, 2);
  second = memcmp(f6, s6, 2);

  ck_assert_int_gt(first, 0);
  ck_assert_int_gt(second, 0);
}

END_TEST

START_TEST(s21_memcpy_test) {
  const char *first;
  const char *second;
  char buffer[100] = "Hello ";

  // TEST 1
  first = s21_memcpy(buffer, "Hello world\0", 12);
  second = memcpy(buffer, "Hello world\0", 12);

  ck_assert_ptr_eq(first, second);

  // TEST 2
  first = s21_memcpy(buffer, "world", 5);
  second = memcpy(buffer, "world", 5);

  ck_assert_ptr_eq(first, second);

  // TEST 3
  first = s21_memcpy(buffer, "a\n\0", 4);
  second = memcpy(buffer, "a\n\0", 4);

  ck_assert_ptr_eq(first, second);

  // TEST 4
  first = s21_memcpy(buffer, " \n\0", 1);
  second = memcpy(buffer, " \n\0", 1);

  ck_assert_ptr_eq(first, second);

  // TEST 5
  first = s21_memcpy(buffer, " \0", 3);
  second = memcpy(buffer, " \0", 3);

  ck_assert_ptr_eq(first, second);

  // TEST 6
  first = s21_memcpy(buffer, "\n\0", 2);
  second = memcpy(buffer, "\n\0", 2);

  ck_assert_ptr_eq(first, second);

  // TEST 7
  first = s21_memcpy(buffer, "", 1);
  second = memcpy(buffer, "", 1);

  ck_assert_ptr_eq(first, second);
}

END_TEST

START_TEST(s21_memmove_test) {
  const char *first;
  const char *second;
  char buffer[100] = "Hello ";

  // TEST 1
  first = s21_memmove(buffer, "Hello world\0", 12);
  second = memmove(buffer, "Hello world\0", 12);

  ck_assert_ptr_eq(first, second);

  // TEST 2
  first = s21_memmove(buffer, "world", 5);
  second = memmove(buffer, "world", 5);

  ck_assert_ptr_eq(first, second);

  // TEST 3
  first = s21_memmove(buffer, "a\n\0", 4);
  second = memmove(buffer, "a\n\0", 4);

  ck_assert_ptr_eq(first, second);

  // TEST 4
  first = s21_memmove(buffer, " \n\0", 1);
  second = memmove(buffer, " \n\0", 1);

  ck_assert_ptr_eq(first, second);

  // TEST 5
  first = s21_memmove(buffer, " \0", 3);
  second = memmove(buffer, " \0", 3);

  ck_assert_ptr_eq(first, second);

  // TEST 6
  first = s21_memmove(buffer, "\n\0", 2);
  second = memmove(buffer, "\n\0", 2);

  ck_assert_ptr_eq(first, second);

  // TEST 7
  first = s21_memmove(buffer, "", 1);
  second = memmove(buffer, "", 1);

  ck_assert_ptr_eq(first, second);
}

END_TEST

START_TEST(s21_memset_test) {
  const char *first;
  const char *second;
  char buffer[100] = "Hello ";

  // TEST 1
  first = s21_memset(buffer, 'w', 12);
  second = memset(buffer, 'w', 12);

  ck_assert_ptr_eq(first, second);

  // TEST 2
  first = s21_memset(buffer, '\n', 5);
  second = memset(buffer, '\n', 5);

  ck_assert_ptr_eq(first, second);

  // TEST 3
  first = s21_memset(buffer, 'a', 5);
  second = memset(buffer, 'a', 5);

  ck_assert_ptr_eq(first, second);

  // TEST 4
  first = s21_memset(buffer, '\0', 1);
  second = memset(buffer, '\0', 1);

  ck_assert_ptr_eq(first, second);

  // TEST 5
  first = s21_memset(buffer, ' ', 100);
  second = memset(buffer, ' ', 100);

  ck_assert_ptr_eq(first, second);

  // TEST 6
  first = s21_memset(buffer, 'p', 2);
  second = memset(buffer, 'p', 2);

  ck_assert_ptr_eq(first, second);

  // TEST 7
  first = s21_memset(buffer, 'q', 1);
  second = memset(buffer, 'q', 1);

  ck_assert_ptr_eq(first, second);
}

END_TEST

START_TEST(s21_strcat_test) {
  const char *first;
  const char *second;
  char s1[100] = "Hello ";

  // TEST 1
  first = s21_strcat(s1, "world");
  second = strcat(s1, "world");

  ck_assert_str_eq(first, second);

  // TEST 2
  first = s21_strcat(s1, "");
  second = strcat(s1, "");

  ck_assert_str_eq(first, second);

  // TEST 3

  first = s21_strcat(s1, "\n");
  second = strcat(s1, "\n");

  ck_assert_str_eq(first, second);
}

END_TEST

START_TEST(s21_strncat_test) {
  const char *first;
  const char *second;
  char s1[100] = "Hello ";

  // TEST 1
  first = s21_strncat(s1, "world", 2);
  second = strncat(s1, "world", 2);

  ck_assert_str_eq(first, second);

  // // TEST 2
  // first = s21_strncat(s1, "", 2);
  // second = strncat(s1, "", 2);

  ck_assert_str_eq(first, second);

  // TEST 3
  first = s21_strncat(s1, "\n", 0);
  second = strncat(s1, "\n", 0);

  ck_assert_str_eq(first, second);
}

END_TEST

START_TEST(s21_strchr_test) {
  const char *first;
  const char *second;
  char s1[100] = "Hello ";

  // TEST 1
  first = s21_strchr(s1, ' ');
  second = strchr(s1, ' ');

  ck_assert_str_eq(first, second);

  // TEST 2
  first = s21_strchr(s1, '\0');
  second = strchr(s1, '\0');

  ck_assert_str_eq(first, second);

  // TEST 3
  first = s21_strchr(s1, 'w');
  second = strchr(s1, 'w');

  ck_assert_ptr_eq(first, second);
}

END_TEST

START_TEST(s21_strcmp_test) {
  int first;
  int second;

  // TEST 1
  char *f1 = "Hello\0";
  char *s1 = "Hello\0";
  first = s21_strcmp(f1, s1);
  second = strcmp(f1, s1);

  ck_assert_int_eq(first, second);

  // TEST 2
  char *f2 = "";
  char *s2 = "";
  first = s21_strcmp(f2, s2);
  second = strcmp(f2, s2);

  ck_assert_int_eq(first, second);

  // TEST 3
  char *f3 = "erg";
  char *s3 = "";
  first = s21_strcmp(f3, s3);
  second = strcmp(f3, s3);

  ck_assert_int_eq(first > 0, second > 0);
}

END_TEST

START_TEST(s21_strncmp_test) {
  int first;
  int second;

  // TEST 1
  char *f1 = "Hello world\0";
  char *s1 = "Hello world\0";
  first = s21_strncmp(f1, s1, 5);
  second = strncmp(f1, s1, 5);

  ck_assert_int_eq(first, second);

  // TEST 2
  char *f2 = "Hello world\n\0";
  char *s2 = "Hello world\n\0";
  first = s21_strncmp(f2, s2, 13);
  second = strncmp(f2, s2, 13);

  ck_assert_int_eq(first, second);

  // TEST 3
  char *f3 = "a\n\0";
  char *s3 = "Hello world\n\0";
  first = s21_strncmp(f3, s3, 3);
  second = strncmp(f3, s3, 3);

  ck_assert_int_eq(first > 0, second > 0);

  // TEST 4
  char *f4 = " \n\0";
  char *s4 = "a\n\0";
  first = s21_strncmp(f4, s4, 0);
  second = strncmp(f4, s4, 0);

  ck_assert_int_eq(first > 0, second > 0);

  // TEST 5
  char *f5 = " \n\0";
  char *s5 = " \0";
  first = s21_strncmp(f5, s5, 1);
  second = strncmp(f5, s5, 1);

  ck_assert_int_eq(first, second);

  // TEST 6
  char *f6 = " \0";
  char *s6 = "\n\0";
  first = s21_strncmp(f6, s6, 2);
  second = strncmp(f6, s6, 2);

  ck_assert_int_eq(first > 0, second > 0);
}

END_TEST

START_TEST(s21_strcpy_test) {
  const char *first;
  const char *second;
  char buffer[100] = "Hello ";

  // TEST 1
  first = s21_strcpy(buffer, "Hello world\0");
  second = strcpy(buffer, "Hello world\0");

  ck_assert_ptr_eq(first, second);

  // TEST 2
  first = s21_strcpy(buffer, "world");
  second = strcpy(buffer, "world");

  ck_assert_ptr_eq(first, second);

  // TEST 3
  first = s21_strcpy(buffer, "a\n\0");
  second = strcpy(buffer, "a\n\0");

  ck_assert_ptr_eq(first, second);

  // TEST 4
  first = s21_strcpy(buffer, " \n\0");
  second = strcpy(buffer, " \n\0");

  ck_assert_ptr_eq(first, second);

  // TEST 5
  first = s21_strcpy(buffer, " \0");
  second = strcpy(buffer, " \0");

  ck_assert_ptr_eq(first, second);

  // TEST 6
  first = s21_strcpy(buffer, "\n\0");
  second = strcpy(buffer, "\n\0");

  ck_assert_ptr_eq(first, second);

  // TEST 7
  first = s21_strcpy(buffer, "\0");
  second = strcpy(buffer, "\0");

  ck_assert_ptr_eq(first, second);
}

END_TEST

START_TEST(s21_strncpy_test) {
  const char *first;
  const char *second;
  char buffer[100] = "Hello ";

  // TEST 1
  first = s21_strncpy(buffer, "Hello world\0", 12);
  second = strncpy(buffer, "Hello world\0", 12);

  ck_assert_ptr_eq(first, second);

  // TEST 2
  first = s21_strncpy(buffer, "world\0", 6);
  second = strncpy(buffer, "world\0", 6);

  ck_assert_ptr_eq(first, second);

  // TEST 3
  first = s21_strncpy(buffer, "a\n\0", 3);
  second = strncpy(buffer, "a\n\0", 3);

  ck_assert_ptr_eq(first, second);

  // TEST 4
  first = s21_strncpy(buffer, " \n\0", 4);
  second = strncpy(buffer, " \n\0", 4);

  ck_assert_ptr_eq(first, second);

  // TEST 5
  first = s21_strncpy(buffer, " \0", 5);
  second = strncpy(buffer, " \0", 5);

  ck_assert_ptr_eq(first, second);

  // TEST 6
  first = s21_strncpy(buffer, "\n\0", 6);
  second = strncpy(buffer, "\n\0", 6);

  ck_assert_ptr_eq(first, second);

  // TEST 7
  first = s21_strncpy(buffer, "\0", 7);
  second = strncpy(buffer, "\0", 7);

  ck_assert_ptr_eq(first, second);
}

END_TEST

START_TEST(s21_to_upper_test) {
  void *result1 = s21_to_upper("Hello world\0");
  ck_assert_str_eq((const char *)result1, "HELLO WORLD\0");
  free(result1);

  void *result2 = s21_to_upper("world\0");
  ck_assert_str_eq((const char *)result2, "WORLD\0");
  free(result2);

  void *result3 = s21_to_upper("a\n\0");
  ck_assert_str_eq((const char *)result3, "A\n\0");
  free(result3);

  void *result4 = s21_to_upper(" \n\0");
  ck_assert_str_eq((const char *)result4, " \n\0");
  free(result4);

  void *result5 = s21_to_upper("HELLO WORLD\0");
  ck_assert_str_eq((const char *)result5, "HELLO WORLD\0");
  free(result5);

  void *result6 = s21_to_upper("\0");
  ck_assert_str_eq((const char *)result6, "\0");
  free(result6);
}
END_TEST

START_TEST(s21_to_lower_test) {
  void *result1 = s21_to_lower("Hello world\0");
  ck_assert_str_eq((const char *)result1, "hello world\0");
  free(result1);

  void *result2 = s21_to_lower("world\0");
  ck_assert_str_eq((const char *)result2, "world\0");
  free(result2);

  void *result3 = s21_to_lower("A\n\0");
  ck_assert_str_eq((const char *)result3, "a\n\0");
  free(result3);

  void *result4 = s21_to_lower(" \n\0");
  ck_assert_str_eq((const char *)result4, " \n\0");
  free(result4);

  void *result5 = s21_to_lower("hello world\0");
  ck_assert_str_eq((const char *)result5, "hello world\0");
  free(result5);

  void *result6 = s21_to_lower("\0");
  ck_assert_str_eq((const char *)result6, "\0");
  free(result6);
}
END_TEST

START_TEST(test_d) {
  int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("298 7 3", "%d%*d%d", &x1, &x2),
                   s21_sscanf("298 7 3", "%d%*d%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("298/02", "%d%*c%d", &x1, &x2),
                   s21_sscanf("298/02", "%d%*c%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("298\n\t 3.1", "%d%d", &x1, &x2),
                   s21_sscanf("298\n\t 3.1", "%d%d", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  int x5, y5;
  ck_assert_int_eq(sscanf("298\n\t 3.1", "%d%d%n", &x1, &x2, &x5),
                   s21_sscanf("298\n\t 3.1", "%d%d%n", &y1, &y2, &y5));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
  ck_assert_int_eq(x5, y5);

  short int x4, y4;
  ck_assert_int_eq(sscanf("298 3", "%d%hd", &x1, &x4),
                   s21_sscanf("298 3", "%d%hd", &y1, &y4));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x4, y4);

  long int x3, y3;
  ck_assert_int_eq(sscanf("298 3", "%ld%hd", &x3, &x4),
                   s21_sscanf("298 3", "%ld%hd", &y3, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);

  ck_assert_int_eq(sscanf("298 3", "%ld%n%hd", &x3, &x1, &x4),
                   s21_sscanf("298 3", "%ld%n%hd", &y3, &y1, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_x) {
  unsigned int x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("298 7 ab", "%x%*x%x", &x1, &x2),
                   s21_sscanf("298 7 ab", "%x%*x%x", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  unsigned short x3, y3;
  unsigned long x4, y4;
  ck_assert_int_eq(sscanf("298 7 ab", "%hX%*i%lx", &x3, &x4),
                   s21_sscanf("298 7 ab", "%hX%*i%lx", &y3, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_o) {
  unsigned int x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("298 7 ab", "%o%*o%o", &x1, &x2),
                   s21_sscanf("298 7 ab", "%o%*o%o", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  short unsigned x3, y3;
  long unsigned x4, y4;
  ck_assert_int_eq(sscanf("298 7 ab", "%ho%*i%lo", &x3, &x4),
                   s21_sscanf("298 7 ab", "%ho%*i%lo", &y3, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_u) {
  unsigned int x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("298 -7 ab", "%u%*u%u", &x1, &x2),
                   s21_sscanf("298 -7 ab", "%u%*u%u", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("298 7 -3", "%u%*u%u", &x1, &x2),
                   s21_sscanf("298 7 -3", "%u%*u%u", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  short unsigned x3, y3;
  long unsigned x4, y4;
  ck_assert_int_eq(sscanf("298 -7 0003", "%hu%*i%lu", &x3, &x4),
                   s21_sscanf("298 -7 0003", "%hu%*i%lu", &y3, &y4));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_i) {
  int x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("0x298 -7 ab", "%i%*i%i", &x1, &x2),
                   s21_sscanf("0x298 -7 ab", "%i%*i%i", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  short x3, y3;
  long x4, y4;
  ck_assert_int_eq(sscanf("298 -7 0xab", "%hi%*i%li", &x3, &x4),
                   s21_sscanf("298 -7 0xab", "%hi%*i%li", &y3, &y4));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("298 -7 0xab", "%hn%i%ln", &x3, &x1, &x4),
                   s21_sscanf("298 -7 0xab", "%hn%i%ln", &y3, &y1, &y4));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x4, y4);
}

END_TEST

START_TEST(test_p) {
  void *x1, *x2, *y1, *y2;
  ck_assert_int_eq(sscanf("298 7 0xab", "%p%*p%p", &x1, &x2),
                   s21_sscanf("298 7 0xab", "%p%*p%p", &y1, &y2));
  ck_assert_int_eq((long)x1, (long)y1);
  ck_assert_int_eq((long)x2, (long)y2);
}

END_TEST

START_TEST(test_f) {
  float x1, x2 = 0, y1, y2 = 0;
  ck_assert_int_eq(sscanf("298.3 4", "%f%f", &x1, &x2),
                   s21_sscanf("298.3 4", "%f%f", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);

  ck_assert_int_eq(sscanf("298.3 0 nAN 4", "%f%*f%*f%f", &x1, &x2),
                   s21_sscanf("298.3 0 Nan 4", "%f%*f%*f%f", &y1, &y2));
  ck_assert_int_eq((x1 - y1) * 1e15, 0);
  ck_assert_int_eq((x2 - y2) * 1e15, 0);

  long double x3, y3;
  ck_assert_int_eq(sscanf("298e-2 iNf 3E3", "%Lf%*f%f", &x3, &x2),
                   s21_sscanf("298e-2 InF 3E3", "%Lf%*f%f", &y3, &y2));
  ck_assert_int_eq((x2 - y2) * 1e15, 0);
  ck_assert_int_eq((x3 - y3) * 1e15, 0);
}

END_TEST

START_TEST(test_c) {
  char x1, x2, y1, y2;
  ck_assert_int_eq(sscanf("0 a", "%c %c", &x1, &x2),
                   s21_sscanf("0 a", "%c %c", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  ck_assert_int_eq(sscanf("0.a", "%c.%c", &x1, &x2),
                   s21_sscanf("0.a", "%c.%c", &y1, &y2));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);

  wchar_t x3, y3;
  ck_assert_int_eq(sscanf("3/5gf", "%lc%*c%cg%c", &x3, &x2, &x1),
                   s21_sscanf("3/5gf", "%lc%*c%cg%c", &y3, &y2, &y1));
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
  ck_assert_int_eq(x3, y3);

  ck_assert_int_eq(sscanf("ȬŚƾ", "%lc%c%c", &x3, &x2, &x1),
                   s21_sscanf("ȬŚƾ", "%lc%c%c", &y3, &y2, &y1));
  ck_assert_int_eq(x3, y3);
  ck_assert_int_eq(x1, y1);
  ck_assert_int_eq(x2, y2);
}

END_TEST

START_TEST(test_s) {
  char x1[10] = "\0", x2[10] = "\0", y1[10] = "\0", y2[10] = "\0";
  ck_assert_int_eq(sscanf("ya ebu sobak", "%9sebu%9s", x1, x2),
                   s21_sscanf("ya ebu sobak", "%9sebu%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);

  ck_assert_int_eq(sscanf("ya ebu sobak", "%9s%*2s%9s", x1, x2),
                   s21_sscanf("ya ebu sobak", "%9s%*2s%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);

  ck_assert_int_eq(sscanf("ya ebu sobak", "%9sf%9s", x1, x2),
                   s21_sscanf("ya ebu sobak", "%9sf%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);

  ck_assert_int_eq(sscanf("  ya", "%9s%9s", x1, x2),
                   s21_sscanf("  ya", "%9s%9s", y1, y2));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);

  wchar_t x3[10], y3[10];
  int x4, y4;
  ck_assert_int_eq(
      sscanf("ya ebu % sobak", "%9ls%9s%%%n%9s", x3, x2, &x4, x1),
      s21_sscanf("ya ebu % sobak", "%9ls%s%%%n%9s", y3, y2, &y4, y1));
  ck_assert_str_eq(x1, y1);
  ck_assert_str_eq(x2, y2);
  ck_assert_int_eq(*x3, *y3);
  ck_assert_int_eq(x4, y4);

  ck_assert_int_eq(sscanf("ȬŚƾ", "%9ls%*s%n%9s", x3, &x4, x1),
                   s21_sscanf("ȬŚƾ", "%9ls%*s%n%9s", y3, &y4, y1));
  ck_assert_str_eq(x1, y1);
  ck_assert_int_eq(*x3, *y3);
  ck_assert_int_eq(x4, y4);
}

END_TEST

// STRING FN #13. STRCSPN -- START
START_TEST(s21_strcspn_test) {
  // TEST 1.
  s21_size_t res1, res2;
  res1 = s21_strcspn("123456789", "9876");
  res2 = strcspn("123456789", "9876");
  ck_assert_int_eq(res1, res2);
  // TEST 2.
  res1 = s21_strcspn("", "9876");
  res2 = strcspn("", "9876");
  ck_assert_int_eq(res1, res2);
  // TEST 3.
  res1 = s21_strcspn("123456789", "");
  res2 = strcspn("123456789", "");
  ck_assert_int_eq(res1, res2);
}

END_TEST
// STRING FN #13. STRCSPN -- END
//////////////////////////////////////////////
// STRING FN #14. STRERROR -- START
START_TEST(s21_strerror_test) {
  // TEST 1. Unknown error -123..0
  for (int i = -123; i < 0; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  // TEST 2. Error 0..106
  for (int i = 0; i <= 106; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
  // TEST 3. Unknown error 107..234
  for (int i = 107; i <= 234; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }
}

END_TEST
// STRING FN #14. STRERROR -- END
//////////////////////////////////////////////
// STRING FN #15. STRLEN -- START
START_TEST(s21_strlen_test) {
  s21_size_t str1, str2;
  // TEST 1.
  str1 = s21_strlen("Lol");
  str2 = strlen("Lol");
  ck_assert_int_eq(str1, str2);
  // TEST 2.
  str1 = s21_strlen("");
  str2 = strlen("");
  ck_assert_int_eq(str1, str2);
}

END_TEST
// STRING FN #15. STRLEN -- END
//////////////////////////////////////////////
// STRING FN #16. STRPBRK -- START
START_TEST(s21_strpbrk_test) {
  // TEST 1.
  char *str11 = "this is a test";
  char *str12 = "this is a test";
  ck_assert_str_eq(s21_strpbrk(str12, "this"), strpbrk(str11, "this"));
  // TEST 2.
  char *str21 = "this is a test";
  char *str22 = "this is a test";
  ck_assert_str_eq(s21_strpbrk(str22, " "), strpbrk(str21, " "));
  // TEST 3.
  char *str31 = "this is a test, this is ...";
  char *str32 = "this is a test, this is ...";
  ck_assert_str_eq(s21_strpbrk(str32, "this"), strpbrk(str31, "this"));
  // TEST 4.
  char *str = "this is a test, this is ...";
  char *str1 = "this is a test, this is ...";
  ck_assert_ptr_eq(s21_strpbrk(str, "prom"), strpbrk(str1, "prom"));
}

END_TEST
// STRING FN #16. STRPBRK -- END
//////////////////////////////////////////////
// STRING FN #17. STRRCHR -- START
START_TEST(s21_strrchr_test) {
  // TEST 1.
  char str1[] = "Hello, Mel";
  int c1 = 'e';
  ck_assert_ptr_eq(s21_strrchr(str1, c1), strrchr(str1, c1));
  // TEST 2.
  char str2[] = "Hello, Mel";
  int c2 = 'p';
  ck_assert_ptr_eq(s21_strrchr(str2, c2), strrchr(str2, c2));
  // TEST 3.
  char str3[] = "";
  int c3 = 'l';
  ck_assert_ptr_eq(s21_strrchr(str3, c3), strrchr(str3, c3));
  // TEST 4.
  char str4[] = "Hello";
  int c4 = 0;
  ck_assert_ptr_eq(s21_strrchr(str4, c4), strrchr(str4, c4));
  // TEST 5.
  char str5[] = "Hello";
  int c5 = 'o';
  ck_assert_ptr_eq(s21_strrchr(str5, c5), strrchr(str5, c5));
  // TEST 6.
  // ck_assert_pstr_eq(s21_strrchr(NULL, '1'), NULL);
}

END_TEST
// STRING FN #17. STRRCHR -- END
//////////////////////////////////////////////
// STRING FN #18. STRSPN -- END
START_TEST(s21_strspn_test) {
  // Test 1. 3
  char *str1 = "0123456789";
  char *sym1 = "210";
  ck_assert_int_eq(s21_strspn(str1, sym1), strspn(str1, sym1));
  // Test 2.
  char *str2 = "12345";
  char *sym2 = "123";
  ck_assert_int_eq(s21_strspn(str2, sym2), strspn(str2, sym2));
  // Test 3.
  char *str3 = "12345";
  char *sym3 = " ";
  ck_assert_int_eq(s21_strspn(str3, sym3), strspn(str3, sym3));
  // Test 4.
  char *str4 = "12345";
  char *sym4 = " ";
  ck_assert_int_eq(s21_strspn(str4, sym4), strspn(str4, sym4));
  // Test 5.
  char *str5 = " ";
  char *sym5 = " ";
  ck_assert_int_eq(s21_strspn(str5, sym5), strspn(str5, sym5));
}

END_TEST
// STRING FN #18. STRSPN -- END
//////////////////////////////////////////////
// STRING FN #19. STRSTRT -- START
START_TEST(s21_strstr_test) {
  // TEST 1.
  char str1[10] = "hello";
  char sym1[10] = "he";
  char *s21_s1 = s21_strstr(str1, sym1);
  char *s1 = strstr(str1, sym1);
  ck_assert_int_eq(s21_s1 - str1 + 1, s1 - str1 + 1);
  // TEST 2.
  char str2[10] = "hello";
  char sym2[10] = "";
  char *s21_s2 = s21_strstr(str2, sym2);
  char *s2 = strstr(str2, sym2);
  ck_assert_int_eq(s21_s2 - str2 + 1, s2 - str2 + 1);
  // TEST 3.
  char str3[10] = "hello";
  char sym3[10] = "qw";
  char *s21_s3 = s21_strstr(str3, sym3);
  char *s3 = strstr(str3, sym3);
  ck_assert_int_eq(s21_s3 - str3 + 1, s3 - str3 + 1);
  // TEST 4.
  char str4[10] = "hello";
  char sym4[10] = "hellp";
  char *s21_s4 = s21_strstr(str4, sym4);
  char *s4 = strstr(str4, sym4);
  ck_assert_int_eq(s21_s4 - str4 + 1, s4 - str4 + 1);
  // TEST 5.
  char str5[1024] = "hello sweet hello";
  char sym5[10] = "hello";
  char *s21_s5 = s21_strstr(str5, sym5);
  char *s5 = strstr(str5, sym5);
  ck_assert_int_eq(s21_s5 - str5 + 1, s5 - str5 + 1);
  // TEST 6.
  ck_assert_ptr_eq(s21_strstr("123", NULL), NULL);
}

END_TEST
// STRING FN #19. STRSTRT -- END
//////////////////////////////////////////////
// STRING FN #20. STRTOK -- START
START_TEST(s21_strtok_test) {
  char str1[30] = "School-21";
  // TEST 1.
  ck_assert_str_eq(s21_strtok(str1, "-"), strtok(str1, "-"));
  // TEST 2.
  ck_assert_str_eq(s21_strtok(str1, ""), strtok(str1, ""));
  // TEST 3.
  ck_assert_str_eq(s21_strtok(str1, "oo"), strtok(str1, "oo"));
  // TEST 4.
  ck_assert_str_eq(s21_strtok(str1, "Sc"), strtok(str1, "Sc"));
  // TEST 5.
  ck_assert_str_eq(s21_strtok(str1, "21"), strtok(str1, "21"));
  // TEST 6.
  ck_assert_ptr_eq(s21_strtok(NULL, "12"), NULL);

  char str2[30] = "+++++";
  ck_assert_ptr_eq(s21_strtok(str2, "+"), strtok(str2, "+"));
}

END_TEST
// STRING FN #20. STRTOK -- END
//////////////////////////////////////////////
// STRING FN C# 3. INSERT -- START
START_TEST(s21_insert_test) {
  // TEST 1.
  char *str1 = "Aboba";
  char *in1 = "kek";
  char *result1 = S21_NULL;
  result1 = s21_insert(str1, in1, 2);
  ck_assert_str_eq(result1, "Abkekoba");
  free(result1);
  // TEST 2.
  char *str2 = "Aboba";
  char *in2 = "kek";
  char *result2 = S21_NULL;
  result2 = s21_insert(str2, in2, 5);
  ck_assert_str_eq(result2, "Abobakek");
  free(result2);
  // TEST 3.
  char *str3 = "";
  char *in3 = "k ek";
  char *result3 = s21_insert(str3, in3, 0);
  ck_assert_str_eq(result3, "k ek");
  free(result3);
  char *str4 = "Aboba   ";
  char *in4 = "k ek";
  char *result4 = s21_insert(str4, in4, 0);
  ck_assert_str_eq(result4, "k ekAboba   ");
  free(result4);
  char *str5 = "Aboba   ";
  char *in5 = S21_NULL;
  char *result5 = s21_insert(str5, in5, 8);
  ck_assert_str_eq(result5, "Aboba   ");
  free(result5);
  char *str6 = S21_NULL;
  char *in6 = "k ek";
  char *result6 = s21_insert(str6, in6, 8);
  ck_assert_ptr_eq(result6, S21_NULL);
  // free(result6);
  char *str7 = "Aboba   ";
  char *in7 = "k ek";
  char *result7 = s21_insert(str7, in7, -1);
  ck_assert_ptr_eq(result7, S21_NULL);
  // free(result7);
}

END_TEST
// STRING FN C# 3. INSERT -- END
//////////////////////////////////////////////
// STRING FN C# 4. TRIM -- START
START_TEST(s21_trim_test) {
  // TEST 1.
  char *str1 = "WoW, I love it!";
  char *ptr1 = "W";
  char *res1 = (char *)s21_trim(str1, ptr1);
  ck_assert_str_eq(res1, "oW, I love it!");
  free(res1);
  // TEST 2.
  char *str2 = "WoW\0, I love it!";
  char *ptr2 = "W";
  char *res2 = (char *)s21_trim(str2, ptr2);
  ck_assert_str_eq(res2, "o");
  free(res2);
  // TEST 3.
  char *str3 = "WoW, I love it!";
  char *ptr3 = "Wo!";
  char *res3 = (char *)s21_trim(str3, ptr3);
  ck_assert_str_eq(res3, ", I love it");
  free(res3);
  // TEST 4.
  char *str4 = "WoW, I love it!";
  char *ptr4 = "P";
  char *res4 = (char *)s21_trim(str4, ptr4);
  ck_assert_str_eq(res4, "WoW, I love it!");
  free(res4);
  // TEST 5.
  char *str5 = "abc";
  char *ptr5 = "abc";
  char *res5 = (char *)s21_trim(str5, ptr5);
  ck_assert_str_eq(res5, "");
  free(res5);
  // TEST 6.
  char *str6 = "     HELLO    ";
  char *ptr6 = " ";
  char *res6 = (char *)s21_trim(str6, ptr6);
  ck_assert_str_eq(res6, "HELLO");
  free(res6);
  char *str7 = "     HELLO    ";
  char *ptr7 = S21_NULL;
  char *res7 = (char *)s21_trim(str7, ptr7);
  ck_assert_str_eq(res7, "HELLO");
  free(res7);
}

END_TEST
// STRING FN C# 4. TRIM -- END

// SPRINTF TESTS START
START_TEST(test_d_printf) {
  int x1 = 234;
  int x2 = -345;
  char *format_string1 = "love %+d % d love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string1, x1, x2),
                   sprintf(buf_for_sprintf, format_string1, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  long int x3 = 2323454;
  short int x4 = -3;
  char *format_string2 = "love %20.10ld %05hd love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  int x5 = 2342;
  int x6 = -345;
  char *format_string3 = "love %+10d %-10d love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5, x6),
                   sprintf(buf_for_sprintf, format_string3, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}

END_TEST

START_TEST(test_x_printf) {
  int x1 = 234234;
  int x2 = 345123;
  int input = 15;
  int count;
  char *format_string1 = "love %.10x %*X %nlove";
  ck_assert_int_eq(
      s21_sprintf(buf_for_s21_sprintf, format_string1, x1, input, x2, &count),
      sprintf(buf_for_sprintf, format_string1, x1, input, x2, &count));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  long int x3 = 23423423;
  long int x4 = 3451231;
  char *format_string2 = "love %#lx %#lX love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}

END_TEST

START_TEST(test_o_printf) {
  int x1 = 234234;
  unsigned short x2 = 34;
  int input = 15;
  int count;
  char *format_string1 = "love %20o %*ho %n love";
  ck_assert_int_eq(
      s21_sprintf(buf_for_s21_sprintf, format_string1, x1, input, x2, &count),
      sprintf(buf_for_sprintf, format_string1, x1, input, x2, &count));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  long int x3 = 23423423;
  long int x4 = 345123123;
  char *format_string2 = "love %020lo %#-15lo love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}

END_TEST

START_TEST(test_u_printf) {
  unsigned int x1 = 234;
  unsigned int x2 = 345;
  char *format_string1 = "love %u %u love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string1, x1, x2),
                   sprintf(buf_for_sprintf, format_string1, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  long unsigned int x3 = 2323454;
  short unsigned int x4 = 3;
  char *format_string2 = "love %lu %hu love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  unsigned int x5 = 2342;
  unsigned int x6 = 345;
  char *format_string3 = "love % 10u %10u love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5, x6),
                   sprintf(buf_for_sprintf, format_string3, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);
  format_string3 = "love %-+ 10u %1.0u love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5, x6),
                   sprintf(buf_for_sprintf, format_string3, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);
  format_string3 = "love %-8.3u %+ 10.2u love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5, x6),
                   sprintf(buf_for_sprintf, format_string3, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);
  format_string3 = "love %*.*u %-+ .3u love";
  ck_assert_int_eq(
      s21_sprintf(buf_for_s21_sprintf, format_string3, x4, x4, x5, x6),
      sprintf(buf_for_sprintf, format_string3, x4, x4, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}

END_TEST

START_TEST(test_i_printf) {
  long int x3 = 2323454;
  short int x4 = 3;
  char *format_string2 = "love %-3li %+03hi love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  int x1 = 0x234;
  int x2 = 0x345;
  int input = 10;
  char *format_string1 = "love %*i %i love";
  ck_assert_int_eq(
      s21_sprintf(buf_for_s21_sprintf, format_string1, input, x1, x2),
      sprintf(buf_for_sprintf, format_string1, input, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}

END_TEST

START_TEST(test_p_printf) {
  int x1 = 234;
  int x2 = 345;
  char *format_string1 = "love %10p %-10p love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string1, &x1, &x2),
                   sprintf(buf_for_sprintf, format_string1, &x1, &x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}

END_TEST

START_TEST(test_f_printf) {
  float x1 = 234.123;
  float x2 = -345.678;
  char *format_string1 = "love %.f %+f love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string1, x1, x2),
                   sprintf(buf_for_sprintf, format_string1, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  long double x3 = 21234.23434;
  long double x4 = -3234.56788;
  char *format_string2 = "love %10.2Lf %+.4Lf love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  double x5 = 0.2341;
  double x6 = -12345;
  char *format_string3 = "love %#f %010f love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5, x6),
                   sprintf(buf_for_sprintf, format_string3, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}

END_TEST

START_TEST(test_g_printf) {
  double x1 = 123.2341;
  double x2 = -0.341;
  char *format_string1 = "love % g %10g love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string1, x1, x2),
                   sprintf(buf_for_sprintf, format_string1, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  long double x3 = 12345.2341;
  long double x4 = -0.00000341;
  char *format_string2 = "love %+.2Lg %10.LG love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  double x5 = -12345;
  double x6 = 0.23453;
  char *format_string3 = "love %#g %-10g love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5, x6),
                   sprintf(buf_for_sprintf, format_string3, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}

END_TEST

START_TEST(test_e_printf) {
  double x1 = 12345.2345;
  double x2 = -0.341;
  int input = 5;
  char *format_string1 = "love %*.*e % E love";
  ck_assert_int_eq(
      s21_sprintf(buf_for_s21_sprintf, format_string1, input, input, x1, x2),
      sprintf(buf_for_sprintf, format_string1, input, input, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  long double x3 = 12345.2345;
  long double x4 = -0.0000345;
  char *format_string2 = "love %+.2Le %10.LE love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  double x5 = 12.098;
  double x6 = -12345;
  char *format_string3 = "love %#e %010e love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5, x6),
                   sprintf(buf_for_sprintf, format_string3, x5, x6));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}

END_TEST

START_TEST(test_c_printf) {
  char x1 = 'i';
  char x2 = 's';
  char *format_string1 = "love %-10c%10c love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string1, x1, x2),
                   sprintf(buf_for_sprintf, format_string1, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  unsigned long x3 = L'Ȭ';
  unsigned long x4 = L'ƾ';
  char *format_string2 = "love %10lc%-10lc love";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}

END_TEST

START_TEST(test_s_printf) {
  char *x1 = "you";
  char *x2 = "peer";
  char *format_string1 = "%10.2s my favourite %-10s";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string1, x1, x2),
                   sprintf(buf_for_sprintf, format_string1, x1, x2));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  char *x5 = S21_NULL;
  char *format_string3 = "%10.2s my favourite";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string3, x5),
                   sprintf(buf_for_sprintf, format_string3, x5));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  wchar_t *x3 = L"шайн";
  wchar_t *x4 = L"ƾȬ";
  char *format_string2 = "%10.2ls брайт %-10ls";
  ck_assert_int_eq(s21_sprintf(buf_for_s21_sprintf, format_string2, x3, x4),
                   sprintf(buf_for_sprintf, format_string2, x3, x4));
  ck_assert_str_eq(buf_for_sprintf, buf_for_s21_sprintf);

  memset(buf_for_sprintf, ' ', 40);
  memset(buf_for_s21_sprintf, ' ', 40);
}

END_TEST
// SPRINTF TESTS END

Suite *

s21_string(void) {
  Suite *s = suite_create("s21_string");

  TCase *s21_string_h = tcase_create("s21_string_h");
  TCase *s21_scanf = tcase_create("s21_scanf");
  TCase *s21_printf = tcase_create("s21_sprintf");

  // s21_string.h
  tcase_add_test(s21_string_h, s21_memchr_test);
  tcase_add_test(s21_string_h, s21_memcmp_test);
  tcase_add_test(s21_string_h, s21_memcpy_test);
  tcase_add_test(s21_string_h, s21_memmove_test);
  tcase_add_test(s21_string_h, s21_memset_test);
  tcase_add_test(s21_string_h, s21_strcat_test);
  tcase_add_test(s21_string_h, s21_strncat_test);
  tcase_add_test(s21_string_h, s21_strchr_test);
  tcase_add_test(s21_string_h, s21_strcmp_test);
  tcase_add_test(s21_string_h, s21_strncmp_test);
  tcase_add_test(s21_string_h, s21_strcpy_test);
  tcase_add_test(s21_string_h, s21_strncpy_test);
  tcase_add_test(s21_string_h, s21_strcspn_test);
  tcase_add_test(s21_string_h, s21_strerror_test);
  tcase_add_test(s21_string_h, s21_strlen_test);
  tcase_add_test(s21_string_h, s21_strpbrk_test);
  tcase_add_test(s21_string_h, s21_strrchr_test);
  tcase_add_test(s21_string_h, s21_strspn_test);
  tcase_add_test(s21_string_h, s21_strstr_test);
  tcase_add_test(s21_string_h, s21_strtok_test);

  tcase_add_test(s21_string_h, s21_to_upper_test);
  tcase_add_test(s21_string_h, s21_to_lower_test);
  tcase_add_test(s21_string_h, s21_insert_test);
  tcase_add_test(s21_string_h, s21_trim_test);

  // s21_sscanf
  tcase_add_test(s21_scanf, test_d);
  tcase_add_test(s21_scanf, test_x);
  tcase_add_test(s21_scanf, test_o);
  tcase_add_test(s21_scanf, test_u);
  tcase_add_test(s21_scanf, test_i);
  tcase_add_test(s21_scanf, test_p);
  tcase_add_test(s21_scanf, test_f);
  tcase_add_test(s21_scanf, test_c);
  tcase_add_test(s21_scanf, test_s);

  //   s21_sprintf
  tcase_add_test(s21_printf, test_d_printf);
  tcase_add_test(s21_printf, test_x_printf);
  tcase_add_test(s21_printf, test_o_printf);
  tcase_add_test(s21_printf, test_u_printf);
  tcase_add_test(s21_printf, test_i_printf);
  tcase_add_test(s21_printf, test_p_printf);
  tcase_add_test(s21_printf, test_f_printf);
  tcase_add_test(s21_printf, test_g_printf);
  tcase_add_test(s21_printf, test_e_printf);
  tcase_add_test(s21_printf, test_c_printf);
  tcase_add_test(s21_printf, test_s_printf);

  suite_add_tcase(s, s21_string_h);
  suite_add_tcase(s, s21_scanf);
  suite_add_tcase(s, s21_printf);

  return s;
}

int main(void) {
  setlocale(LC_ALL, "");
  int number_failed;
  Suite *s;
  SRunner *sr;
  s = s21_string();
  sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_VERBOSE);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
