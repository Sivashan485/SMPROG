#include <stdio.h>
#include <stdlib.h>

int main(){
  int a = 32; // any positive number

  if(a > 0 && ((a& a-1) ==0)){ 
    //Bei Bitweise and sollte res = 0 
    printf("%d is a power of 2", a); 
  }

  return EXIT_SUCCESS;
}