#include <stdio.h>
#include <string.h>

int my_strlen(char *str) {
  char* s; //inst char pointer
  for(s = str; *s; s++); //traverses through str until null
  return (s - str); //subtracts memory addresses
}

char * my_strcpy(char *dst, char *src) {
  char* original_location = dst;
  while ((*dst++ = *src++));
  return original_location;
}

int main() {
  char *s = "Hello";
  printf("TESTING STRLEN\nLength of %s:\n\tstrlen: %lu\n\tmy_strlen: %d\n\n", s, strlen(s), my_strlen(s));

  char dst[256] = "hh";
  char src[] = "Copy this";


  char my_dst[256] = "hh";
  char my_src[] = "Copy this";
  printf("TESTING STRCPY\nTo copy: %s\nstrcopy(dst, src) --> %s\nmy_strcpy(dst, src) --> %s\n", src, strcpy(dst, src), my_strcpy(my_dst, my_src));
}
