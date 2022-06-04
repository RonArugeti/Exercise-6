#define SignedBinChar(bin,mask,byte) do{if (mask & byte){\
    for (int i = 0; i < 8; i++) {bin <<= 1;\
        if (byte & mask) bin |= 1; byte <<= 1;}\
}else { bin <<= 8; bin|= byte;}\
}while(0)
#include <stdio.h>
int pack4CharsInt(char c1, char c2, char c3, char c4);
int checkEvenParity(short input);
void print_binaryInt(int number);
int main() {
    char a = 0b11011001;
    char b = 0b00101010;
    char c = 0b10100111;
    char d = 0b01001100;
    
    short in = 0b1100011100001100;
    int numberFromBit = pack4CharsInt(a, b, c, d);
    print_binaryInt(numberFromBit);
    printf("\n");
    checkEvenParity(in);

    return 0;
}
int pack4CharsInt(char c1, char c2, char c3, char c4){
    int d = 0;
    unsigned char mask = (unsigned char)128;
    
    SignedBinChar(d, mask, c1);
    SignedBinChar(d, mask, c2);
    SignedBinChar(d, mask, c3);
    SignedBinChar(d, mask, c4);

    return d;
}
int checkEvenParity(short input)
{
    int count = 0;
    unsigned short mask = 0b0000000000000001;
    
    for (int i = 0; i < 16; i++) {
        if (input & mask) {
            count++;
        }
        mask <<= 1;
    }
    if (!(count % 2))
    return 1;
    return 0;
}

void print_binaryInt(int number)
{
    int mask = 0x80000000;
    for (int i = 0; i < 32; i++) {
        (number & mask)? printf("%d",1): printf("%d",0);
        number <<= 1;
    }
    printf("\n");
}
