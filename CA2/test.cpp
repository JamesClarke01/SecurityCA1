#include <iostream>
#include <stdint.h>
#include <stdio.h>

uint8_t getByte(uint32_t word, int i) {
    return (word >> (i * 8)) & 0xFF;

}

int main(void) {
    uint32_t key =  0x0f1571c9;

    printf("0x%X", getByte(key,1));  //Accesses bit starting from back

}