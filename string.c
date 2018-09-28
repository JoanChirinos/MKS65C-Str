#include <stdio.h>
#include <string.h>

int my_strlen(char *str) {
  char* s; //inst char pointer
  for(s = str; *s; s++); //traverses through str until null
  return (s - str); //subtracts memory addresses
}

char* my_strcpy(char* dst, char* src) {
  char* original_location = dst;
  while ((*dst++ = *src++));
  return original_location;
}

char* my_strncpy(char* dst, char* src, int n) {
  char* original_location = dst;
  while(n--) {
    *dst++ = *src++;
  }
  *dst = '\0';
  return original_location;
}

char* my_strcat(char* dst, char* src) {
  //takes address for dst, adds the length to go to the end, then copies src onto it
  my_strcpy(dst + my_strlen(dst), src);
  return dst; //returns dst (start of string)
}

char* my_strncat(char* dst, char* src, int n) {
  my_strncpy(dst + my_strlen(dst), src, n);
  return dst; //returns dst (start of string)
}

int main() {
  char *s = "Hello";
  printf("TESTING STRLEN\nLength of %s:\n\tstrlen: %lu\n\tmy_strlen: %d\n\n", s, strlen(s), my_strlen(s));

  char cpy_dst[256] = "hh";
  char cpy_src[] = "Copy this";
  char my_cpy_dst[256] = "hhh";
  char my_cpy_src[] = "Copy this";
  printf("TESTING STRCPY\nTo copy: %s\nstrcopy(cpy_dst, cpy_src) --> %s\nmy_strcpy(cpy_dst, cpy_src) --> %s\n\n", cpy_src, strcpy(cpy_dst, cpy_src), my_strcpy(my_cpy_dst, my_cpy_src));

  char ncpy_dst[256] = "hh";
  char ncpy_src[] = "Copy this wait never mind dont";
  char my_ncpy_dst[256] = "hhh";
  char my_ncpy_src[] = "Copy this please wait never mind dont";
  printf("TESTING STRNCPY\nTo copy: %s\nstrncopy(ncpy_dst, ncpy_src) --> %s\nmy_strncpy(ncpy_dst, ncpy_src) --> %s\n\n", ncpy_src, strncpy(ncpy_dst, ncpy_src, 9), my_strncpy(my_ncpy_dst, my_ncpy_src, 9));

  char cat_dst[256] = "Hello";
  char cat_src[] = " world!";
  char my_cat_dst[256] = "Hello";
  char my_cat_src[] = " world!";
  printf("TESTING STRCAT\nchar cat_dst[256] = \"Hello\";\nchar cat_src[] = \" world!\";\nstrcat(cat_dst, cat_src) --> %s\nmy_strcat(my_cat_dst, my_cat_src) --> %s\n\n", strcat(cat_dst, cat_src), my_strcat(my_cat_dst, my_cat_src));

  char ncat_dst[256] = "Hello";
  char ncat_src[] = " world!!!!!";
  char my_ncat_dst[256] = "Hello";
  char my_ncat_src[] = " world!!!!!";
  printf("TESTING STRNCAT\nchar ncat_dst[256] = \"Hello\";\nchar ncat_src[] = \" world!!!!!\";\nstrncat(ncat_dst, ncat_src, 7) --> %s\nmy_strncat(my_ncat_dst, my_ncat_src, 7) --> %s\n\n", strncat(ncat_dst, ncat_src, 7), my_strncat(my_ncat_dst, my_ncat_src, 7));


}
