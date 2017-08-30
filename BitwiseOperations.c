#include <stdio.h>
#include <string.h>

/* Bitwise OR används typiskt för att ett-ställa bitar.
Bitwise AND används typiskt för att nollställa bitar.
Bitwise XOR används typiskt för att invertera bitar.

*/

// funktion som tar en byte som input och printar ut det binärt
// Ex. 00001001 för byte = 9.
void printBinary(unsigned char byte) {
  for(int i=7; i>=0; i--) {
    int bit = (byte >> i) & 0x01; // Först högerskift och sedan Bitwise AND
    printf("%d", bit);
  }
}

// för shorts (16-bitar)
void printBinaryShort(unsigned short number) {
  for(int i=15; i>=0; i--) {
    int bit = (number >> i) & 0x01;
    printf("%d", bit);
  }
}

// för ints (32-bitar)
void printBinaryInt(unsigned int number) {
  for(int i=31; i>=0; i--) {
    int bit = (number >> i) & 0x01;
    printf("%d", bit);
  }

}

// en funktion som tar binär byte (sträng) och printar ut den som ett decimaltal
// Ex. char str[] = "00001001" ska ge utskriften 9.
void printDecimal(char str[]) {
  unsigned char byte = 0;
  for(int i=0;i<8; i++){
    if(stri[i] == '1') {
      byte |= (1<<(7-1));
    }
  }
  printf("%d", byte);
}


void clearscreen() {
  for(int i=0; i<80; i++) {
    printf("\n");
  }
}


int main() {
  unsigned char byte = 128;
  printbinary(byte);

  char str[] = "00001001";
  printDecimal(str);

// skapa en unsigned char c = 128, Ettställ bit 1,3 och 5.
// Antag att bitarna numreras 0-7. Verifiera och skriv ut decimaltalet.
  unsigned char byte1 = 128;
  printbinary(byte1); printf("\n");
  byte1 |= (1<<1 | 1<<3 | 1<<5);
  printbinary(byte1); prinft("\n");
  printf("%d\n", byte1);
    return 0;
}
