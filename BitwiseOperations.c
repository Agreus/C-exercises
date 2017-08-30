#include <stdio.h>
#include <string.h>
#include <stdlib.h> //för abs()
#include <windows.h> // innehåller Sleep()

/*
Bitwise OR (a | b)  används typiskt för att ett-ställa bitar.
Bitwise AND (a & b) används typiskt för att nollställa bitar.
Bitwise XOR (a ^ b) används typiskt för att invertera vissa bitar.
Bitwise NOT (~a)    används för att invertera alla bitar
Bitwise left shift (a << b)
bitweise right shift (a >> b)

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
  for(int i=0; i<8; i++) {
      if(str[i] == '1') {
        byte |= (1<<(7-i));
      }
  }
  printf("%d", byte);
}

void clearscreen() {
  for(int i=0; i<80; i++) {
    printf("\n");
  }
}

void printSpaces(int n) {
  for(int i=0; i<n; i++) {
    printf(" ");
  }
}


// test
int main1() {
  unsigned char byte = 128;
  printBinary(byte);

  printf("\n");
  char str[] = "00001001";
  printDecimal(str);


// skapa en unsigned char c = 128, Ettställ bit 1,3 och 5.
// Antag att bitarna numreras 0-7. Verifiera och skriv ut decimaltalet.
  unsigned char byte1 = 128;
  printBinary(byte1); printf("\n");
  byte1 |= (1<<1 | 1<<3 | 1<<5);
  printBinary(byte1);printf("\n");
  printf("%d\n", byte1);
  // hexadecimalt genom använda printf("%x\n", tal);
  // Hexadecimaltal anges i C med prefixet 0x.
  printf("%x\n", byte1);

    return 0;
}

int main2(){
  while (1) {
    unsigned short a = 0x8000, b = 0x0001;
    for(int i=0; i<15; i++) {
      clearscreen();
      a >>= 1;
      b <<= 1;
      printBinary(a | b);
      printf("\n");
      // without the sleep, the eternal loop may
      // also cause the program to be harder to
      // terminate.
      Sleep(250); // för Windows: Sleep(250); milisekunder
    }
  }
	return 0;
}


// Texten scrollar omväxlande till höger/vänster.
int main()
{
    unsigned short a = 1, b = 0x8000;
    int scrollWidth = 50;
    int loopIter = 0;
    while (1)
    {
        clearscreen();

        // Hantera horisontell bouncing scroll
        // låt scrolliter loopa runt från 0 t.om. 99;
        int scrollIter = loopIter % (2*scrollWidth);
        int pos = 35 + scrollWidth - abs(scrollWidth - scrollIter);
        printSpaces(pos);

        // hantera bit-scroll
        if((loopIter % 2) != 0) { // uppdatera bitmönstret endast varannan iteration.
            a = (a <= 1) ? 0x8000 : a >> 1;
            b = (b == 0x8000) ? 0x0001 : b << 1;
        }
        printBinary(a | b);

        printf("\n");
        Sleep(333);
        loopIter++;
    }
    return 0;
}
