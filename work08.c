#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

//HELPERS
//-------------------------------------------------------
int power(int x, int y) {
  int ans = 1;
  for (y; y; y--) {
    ans *= x;
  }
  return ans;
}

char mode (int place) {
  //determining which place you are = the correct letter
  char p;
  if (place == 2) { p = 'r'; }
  else if (place == 1) { p = 'w'; }
  else { p = 'x'; }
  return p;
 }


//permHelp: breaks down one octal digit into the rwx form
//          which correlates with the digit in binary form
//-------------------------------------------------------
char * permHelp (int num) {
  char * ans = (char *) malloc(4);
  int count = 2; 
  char p;
  //traverse thrice because greatest power of 2 below 7 is 2^2
  while (count >= 0) {
    //can you subtract the power of 2?
    if (num - power(2, count) > -1) {
      num -= power(2, count);
      //determining which place you are = the correct letter
      p = mode(count);
      //set the place as the letter
      ans[2-count] = p;
    } else {
      //binary digit doesn't exist; put a -
      ans[2-count] = '-';
    }
    count--;
  }
  //end last one with null
  ans[2-count] = 0;
  return ans;
}

//perm: Breaks down three digit octal into three separate
//      digits, permHelps each one and compiles it in a 9
//      bits
//-------------------------------------------------------
char * perm (mode_t mode) {
  char * perm = (char *) malloc(9);
  int count;
  int remainder;
  char * p;
  for (count = 2; count > -1; count--) {
    remainder = mode % 8;
    p = permHelp(remainder);
    //copy the rwz form into a 3 char slot
    strncpy(perm+count*3, p, 3); 
    free(p);
    mode = mode / 8;
  }
  return perm;
}


//printSizes: puts memory into B, KB, MB, and GB form
//-------------------------------------------------------
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

  printf("\nFile permissions in readable form: \n");
  char * permission = perm(f_size);
  printf("%s\n", permission);
  free(permission);
}

