#include <stdlib.h>
#include <stdio.h>

int main(){
  char word[8] = "sREedEv";
  char *wordptr = &word[0];

  while(wordptr < &word[7]) {

    //  & '_' 01011111     OR ' ' 00100000
    printf("UPPERCASE: %c\n", *wordptr & '_'); // converts the char into uppercase regardless of the current casing    Mit  bringt man den 5 BIT zu uppercase
    printf("LOWERCASE: %c\n", *wordptr | ' '); // converts the char into lowercase regardless of the current casing    5 BIT Wenn 1 ist dann wird Sie lower  um den 5 Bit auf 1 bringen kann man 00100000 verwenden. 
    wordptr++;
  }

  return EXIT_SUCCESS;
}