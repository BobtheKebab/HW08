#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

int main() {

  struct stat yoshi;
  stat("work08.c", &yoshi);


  printf("File size: %ld\n", yoshi.st_size);
  // find remainder to get last three digits; 8 to the third power
  int f_size = yoshi.st_mode % 512;
  
  printf("File mode: %o\n", f_size);
  printf("Last access: %s\n", ctime( &yoshi.st_atime ));
  
}

