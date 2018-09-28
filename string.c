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

char* my_strcat(char* dst, char* src) {
  //takes address for dst, adds the length to go to the end, then copies src onto it
  my_strcpy(dst + my_strlen(dst), src);
  return dst; //returns dst (start of string)
}

char* my_strncat(char* dst, char* src, int n) {
  char* p = dst + my_strlen(dst); //location to begin copying
  while (n--) {
    *p++ = *src++;
  }
  return dst;
}

int main() {
  char *s = "Hello";
  printf("TESTING STRLEN\nLength of %s:\n\tstrlen: %lu\n\tmy_strlen: %d\n\n", s, strlen(s), my_strlen(s));

  char dst[256] = "hh";
  char src[] = "Copy this";
  char my_dst[256] = "hh";
  char my_src[] = "Copy this";
  printf("TESTING STRCPY\nTo copy: %s\nstrcopy(dst, src) --> %s\nmy_strcpy(dst, src) --> %s\n\n", src, strcpy(dst, src), my_strcpy(my_dst, my_src));

  char cat_dst[256] = "Hello";
  char cat_src[] = " world!";
  char my_cat_dst[256] = "Hello";
  char my_cat_src[] = " world!";
  printf("TESTING STRCAT\nchar cat_dst[256] = \"Hello\";\nchar cat_src[] = \" world!\";\nstrcat(cat_dst, cat_src) --> %s\nmy_strcat(my_cat_dst, my_cat_src) --> %s\n\n", strcat(cat_dst, cat_src), my_strcat(my_cat_dst, my_cat_src));

  char ncat_dst[256] = "Hello";
  char ncat_src[] = " world!!!!!";
  char my_ncat_dst[256] = "Hello";
  char my_ncat_src[] = " world!!!!!";
  printf("TESTING STRNCAT\nchar ncat_dst[256] = \"Hello\";\nchar ncat_src[] = \" world!\";\nstrncat(ncat_dst, ncat_src, 7) --> %s\nmy_strncat(my_ncat_dst, my_ncat_src, 7) --> %s\n\n", strncat(ncat_dst, ncat_src, 7), my_strncat(my_ncat_dst, my_ncat_src, 7));
}
