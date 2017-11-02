#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>


int power(int x, int y) {
  int ans = 1;
  for (y; y; y--) {
    ans *= x;
  }
  return ans;
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
  printf("%s\n", ans);
  return ans;
}

char * perm (mode_t mode) {
  /*
  char * ans = (char *) malloc(100);
  printf("Check malloc'd data: %s\n", ans);
  int temp = mode % 512, count = 0, num = temp;
  printf("Mode: %o\n", num);
  while (count < 3) {
    printf("%o mod 12 : %o\n", num, num % 12);
    //num -= num % 12;
    strcat(ans, permHelp(num % 10));
    printf("after strcat: %s\n", ans);
   
    printf("New num: %o div %d is %d\n", num, 10, num / 10);
    num = num / 12;
    count++;
  }
 
  return (char *) ans;
  */
  mode = mode % 512; //take last three digits
  char perm[9];
  int count;
  int remainder;
  for (count = 2; count > -1; count--) {
    remainder = mode % 8;
    int place = count * 3;
    perm + place = permHelp(remainder);
    mode = mode / 8;
  }
  
}

char * sample() {
  char * bob = "apples";
  return bob;
}

void printSizes (off_t size) {
  printf(" B: %fB\nKB: %fKB\nMB: %fMB\nGB: %fGB\n",
	 (float) size,
	 (float) size / 1000,
	 (float) size / 1000000,
	 (float) size / 1000000000);
} 

int main() {

  struct stat yoshi;
  stat("work08.c", &yoshi);

  printf("\nLOOKING AT WORK08.C\n");
  printf("--------------------------------\n");
  printf("File size: %ld\n", yoshi.st_size);
  // find remainder to get last three digits; 8 to the third power
  int f_size = yoshi.st_mode;
  printf("File mode: %o\n", f_size % 512);
  printf("Last access: %s\n", ctime( &yoshi.st_atime ));

  printf("File size in different units:\n");
  printSizes(yoshi.st_size);
  //  printf("File permissions in ls-l format: %s\n", perm(yoshi.st_mode));
  //  printf("%d\n", power(2, 2));

  printf("\nFile permissions in readable form: \n");
  printf("permissions 4: %s\n", permHelp(4));
  printf("permissions 6: %s\n", permHelp(6));
  // printf("%s\n", perm(f_size));

  printf("%s\n", sample());
}

