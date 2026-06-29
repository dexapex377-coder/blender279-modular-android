#ifndef __BLI_STRING_H__
#define __BLI_STRING_H__

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#define BLI_snprintf snprintf
#define BLI_snprintf_rlen snprintf

#ifdef __cplusplus
extern "C" {
#endif

char *BLI_strdupn(const char *str, size_t len);
char *BLI_strdup(const char *str);
char *BLI_strdupcat(const char *str1, const char *str2);
char *BLI_strncpy(char *dst, const char *src, size_t maxcpy);
size_t BLI_strncpy_ensure_pad(char *dst, const char *src, char pad, size_t maxncpy);
char *BLI_strncat(char *dst, const char *src, size_t maxncpy);
size_t BLI_str_format_int_grouped(char *dst, int num);
size_t BLI_str_format_byte_unit(char *dst, unsigned int len, float bytes, int unit);
int BLI_strcasecmp(const char *s1, const char *s2);
int BLI_strncasecmp(const char *s1, const char *s2, size_t len);
int BLI_sprintf(char *dst, size_t max, const char *format, ...);
int BLI_vsnprintf(char *dst, size_t max, const char *format, va_list arg);
char *BLI_str_escape(char *dst, const char *src, size_t dst_maxncpy);
char *BLI_str_unescape(char *dst, const char *src, size_t src_maxncpy);
int BLI_string_find_split_words(const char *str, int str_maxlen, int delim, int *r_words, int r_words_len);
int BLI_str_quoted_substr_range(const char *str, const char *prefix, int *r_start, int *r_end);
char *BLI_str_quoted_substrN(const char *str, const char *prefix);
void BLI_str_replace_char(char *str, char orig, char repl);
int BLI_str_rstrip(char *str);
int BLI_str_starts_with(const char *str, const char *pref);
int BLI_str_endswith(const char *str, const char *suf);

int BLI_string_has_suffix(const char *name, const char *suffix);
int BLI_string_has_prefix(const char *name, const char *prefix);

#ifdef __cplusplus
}
#endif

#endif
