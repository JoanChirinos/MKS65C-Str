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
  printf("TESTING STRLEN\nLength of %s:\n\tstrlen: %d\n\tmy_strlen: %d\n", s, strlen(s), my_strlen(s));
}
