#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>


char * perm (mode_t mode) {
  int num = mode % 512;
  
}

char * permHelp (int num) {
  char ans[3];
  int count = 2;
  char p;
  while (count >= 0) {
    if (num - power(2, count) > -1) {
      num -= power(2, count);
      if (count == 2) { p = 'r'; }
      else if (count == 1) { p = 'w'; }
      else { p = 'x'; }
      ans[2-count] = p;
    } else {
      ans[2-count] = '-';
    }
    count--;
  }
  return ans;
}

int power(int x, int y) {
  int ans = 1;
  for (y; y; y--) {
    ans *= x;
  }
  return ans;
}

char * format(int ary[]) {
  int count = 0;
  while (count < 3) {
    
  }
}

int main() {

  struct stat yoshi;
  stat("work08.c", &yoshi);


  printf("File size: %ld\n", yoshi.st_size);
  // find remainder to get last three digits; 8 to the third power
  int f_size = yoshi.st_mode % 512;
  
  printf("File mode: %o\n", f_size);
  printf("Last access: %s\n", ctime( &yoshi.st_atime ));
  //  printf("File permissions in ls-l format: %s\n", perm(yoshi.st_mode));
  //  printf("%d\n", power(2, 2));
  printf("permissions 4: %s\n", permHelp(4));
  printf("permissions 6: %s\n", permHelp(1));
}

