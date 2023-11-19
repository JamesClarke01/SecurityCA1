#include <iostream>
#include <stdint.h>

//RotWord
int rotWord(uint32_t word) {
    
    //starting from rhs
    //shift desired byte to the right then mask out all bits except the byte needed
    uint8_t byte0 = word & 0xFF; 
    uint8_t byte1 = (word >> 8) & 0xFF;
    uint8_t byte2 = (word >> 16) & 0xFF;
    uint8_t byte3 = (word >> 24) & 0xFF;

    //combine all bytes together in rotated order
    return (byte2 << 24) | (byte1 << 16) | (byte0 << 8) | byte3;  
}

//SubWord





//Rcon

//XorWords

int main(void) {
    
    uint32_t key[4] = {0x0F1571C9, 0x47D9E859, 0x0CB7ADD6, 0xAF7F6798};  //key is made up of 4 4-byte "words" (16 bytes)
    uint32_t w[44];  //output is 44 4-byte "words" (176 bytes) 
    uint32_t temp;
    int i;

    //Populate the first 4 words with key
    for (i = 0; i < 4; i++) {
        w[i] = key[i];
    }

    printf("%X", rotWord(key[0]));

    /*
    for (i = 4; i < 44; i++) {  //for each word (excluding first 4)
        //temp = w[i-1];

    } 
    */

}