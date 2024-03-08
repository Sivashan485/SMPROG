#include <stdlib.h>
#include <stdio.h>

int main() {
  unsigned int number = 0x75;
  unsigned int bit = 3; // bit at position 3

  // Setting a bit
  number  |=(1 << bit);   // Setzen eines Bits |
  printf("number = 0x%02X\n", number);

  // Clearing a bit
  bit = 1;  
  number &= ~(1 << bit); // Löschen eines Bits mit & löschen und ~ Einer komplement
  printf("number = 0x%02X\n", number);

  // Toggling a bit
  bit = 0;
  number ^= (1 << bit) ; // Wechseln eines Bits  ^ XOR

  printf("number = 0x%02X\n", number);
  
  return EXIT_SUCCESS;
}