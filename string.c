#include <stdio.h>
#include <string.h>

int my_strlen(char *s) {
  int ctr = 0;
  while(*s) {
    s++;
    ctr++;
  }
  return ctr;
}

int main() {
  char *s = "Hello";
  printf("TESTING STRLEN\nLength of %s: %d\n", s, my_strlen(s));
}
