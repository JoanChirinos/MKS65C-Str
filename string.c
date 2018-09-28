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

int my_strcmp(char* s1, char* s2) {
  //while neither are null, check if they're !=. If so, return correct val.
  //else, increment both and check again
  for( ; *s1 && *s2; *s1++, *s2++) {
    if (*s1 < *s2) return -1;
    else if (*s1 > *s2) return 1;
  }
  return 0;
}

int main() {
  char *s = "Hello";
  printf("TESTING STRLEN\nLength of %s:\n\tstrlen: %lu\n\tmy_strlen: %d\n\n", s, strlen(s), my_strlen(s));

  char cpy_dst[256] = "hh";
  char cpy_src[] = "Copy this";
  char my_cpy_dst[256] = "hhh";
  char my_cpy_src[] = "Copy this";
  printf("TESTING STRCPY\n");
  printf("To copy: %s\n", cpy_src);
  printf("strcopy(cpy_dst, cpy_src) --> %s\n", strcpy(cpy_dst, cpy_src));
  printf("my_strcpy(cpy_dst, cpy_src) --> %s\n\n", my_strcpy(my_cpy_dst, my_cpy_src));

  char ncpy_dst[256] = "hh";
  char ncpy_src[] = "Copy this wait never mind dont";
  char my_ncpy_dst[256] = "hhh";
  char my_ncpy_src[] = "Copy this please wait never mind dont";
  printf("TESTING STRNCPY\n");
  printf("To copy: %s\n", ncpy_src);
  printf("strncopy(ncpy_dst, ncpy_src) --> %s\n", strncpy(ncpy_dst, ncpy_src, 9));
  printf("my_strncpy(ncpy_dst, ncpy_src) --> %s\n\n", my_strncpy(my_ncpy_dst, my_ncpy_src, 9));

  char cat_dst[256] = "Hello";
  char cat_src[] = " world!";
  char my_cat_dst[256] = "Hello";
  char my_cat_src[] = " world!";
  printf("TESTING STRCAT\n");
  printf("char cat_dst[256] = \"Hello\";\n");
  printf("char cat_src[] = \" world!\";\n");
  printf("strcat(cat_dst, cat_src) --> %s\n", strcat(cat_dst, cat_src));
  printf("my_strcat(my_cat_dst, my_cat_src) --> %s\n\n", my_strcat(my_cat_dst, my_cat_src));

  char ncat_dst[256] = "Hello";
  char ncat_src[] = " world!!!!!";
  char my_ncat_dst[256] = "Hello";
  char my_ncat_src[] = " world!!!!!";
  printf("TESTING STRNCAT\n");
  printf("char ncat_dst[256] = \"Hello\";\n");
  printf("char ncat_src[] = \" world!!!!!\";\n");
  printf("strncat(ncat_dst, ncat_src, 7) --> %s\n", strncat(ncat_dst, ncat_src, 7));
  printf("my_strncat(my_ncat_dst, my_ncat_src, 7) --> %s\n\n", my_strncat(my_ncat_dst, my_ncat_src, 7));

  char cmp_s1[] = "Yo";
  char cmp_s2[] = "Yo";
  char cmp_s3[] = "yo?";
  char cmp_s4[] = "yo";
  printf("TESTING STRCMP\n");
  printf("char cmp_s1[] = \"Yo\";\n");
  printf("char cmp_s2[] = \"Yo\";\n");
  printf("char cmp_s3[] = \"yo?\";\n");
  printf("char cmp_s3[] = \"yo\";\n");

  printf("strcmp(cmp_s1, cmp_s2) --> %d\n", strcmp(cmp_s1, cmp_s2));
  printf("strcmp(cmp_s1, cmp_s3) --> %d\n", strcmp(cmp_s1, cmp_s3));
  printf("strcmp(cmp_s3, cmp_s1) --> %d\n", strcmp(cmp_s3, cmp_s1));
  printf("strcmp(cmp_s1, cmp_s4) --> %d\n", strcmp(cmp_s1, cmp_s4));
  printf("strcmp(cmp_s2, cmp_s4) --> %d\n\n", strcmp(cmp_s2, cmp_s4));

  printf("my_strcmp(cmp_s1, cmp_s2) --> %d\n", my_strcmp(cmp_s1, cmp_s2));
  printf("my_strcmp(cmp_s1, cmp_s3) --> %d\n", my_strcmp(cmp_s1, cmp_s3));
  printf("my_strcmp(cmp_s3, cmp_s1) --> %d\n", my_strcmp(cmp_s3, cmp_s1));
  printf("my_strcmp(cmp_s1, cmp_s4) --> %d\n", my_strcmp(cmp_s1, cmp_s4));
  printf("my_strcmp(cmp_s2, cmp_s4) --> %d\n\n", my_strcmp(cmp_s2, cmp_s4));

}
