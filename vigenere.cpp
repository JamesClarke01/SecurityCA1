#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

int charToAlphaNum(char c) {
    int alphaStart;

    if(islower(c)) {
        alphaStart = 'a';
    } else {
        alphaStart = 'A';
    }

    return c - alphaStart;
}

char alphaNumToChar(int x) {
    int alphaStart = 'a';

    return x + alphaStart;
}

char encryptChar(char plainChar, char keyChar) {
    int alphaNum = (charToAlphaNum(plainChar) + charToAlphaNum(keyChar)) % 26;
    
    return alphaNumToChar(alphaNum);
}

char decryptChar(char encryptChar, char plainChar) {
    int alphaNum = (charToAlphaNum(encryptChar) - charToAlphaNum(plainChar)) % 26;
    
    if (alphaNum < 0) {
        alphaNum += 26;
    }
    return alphaNumToChar(alphaNum);
}


std::string encrypt(std::string key, std::string plainText) {
    int j, i;
    std::string encryptText;
    
    j = 0;
    for(i = 0; i < plainText.length(); i++) {
        if (isspace(plainText[i])) {
            encryptText += plainText[i];
        } else {
            encryptText += encryptChar(plainText[i], key[j]);

            if(j+1 == key.length()) {
                j = 0;
            } else {
                j++;
            }
        }
    } 

    return encryptText;   
}

std::string decrypt(std::string key, std::string encryptText) {
    int j, i;
    std::string decryptText;

    j = 0;
    for(i = 0; i < encryptText.length(); i++) {
        if (isspace(encryptText[i])) {
            decryptText += encryptText[i];
        } else {
            decryptText += decryptChar(encryptText[i], key[j]);

            if(j+1 == key.length()) {
                j = 0;
            } else {
                j++;
            }
        }
    } 

    return decryptText; 
}


int main(int argc, char** argv)
{
    int i, j;
    std::string inputFileName;
    std::string outputFileName;
    std::string input;
    std::string output;
    std::string key;

    if (argc != 5) {
        std::cout << "Incorrect number of arguements given";
        return 1;
    }

    key = argv[2];
    inputFileName = argv[3];
    outputFileName = argv[4];

    std::ifstream inputStream(inputFileName);
    std::ofstream outputStream(outputFileName);

    std::getline(inputStream, input);
    
    if(strcmp(argv[1], "-e") == 0) {        
        outputStream << encrypt(key, input);
    } else if (strcmp(argv[1], "-d") == 0) {
        outputStream << decrypt(key, input);
    }

    return 0;    
}