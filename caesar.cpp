#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

void encrypt(int key, std::string &input, std::string &output) {
    char a, z, plainLetter;
    
    for(int i = 0; i < input.length(); i++) {
        plainLetter = input[i];

        if (isspace(plainLetter)) { 
            output = output + plainLetter; 
        } else {
            if (islower(plainLetter)) {
                a = 'a';
                z = 'z';
            } else if (isupper(plainLetter)) {
                a = 'A';
                z = 'Z';
            }

            if (plainLetter + key <= z) {
                output += plainLetter + key;
            } else {
                output += (a-1) + (plainLetter + key - z);
            }
        }
    }
}

void decrypt(int key, std::string &input, std::string &output) { 
    char plainLetter, a, z;
    
    for(int i = 0; i < input.length(); i++) {
        plainLetter = input[i];

        if (isspace(plainLetter)) { 
            output = output + plainLetter; 
        } else {
            if (islower(plainLetter)) {
                a = 'a';
                z = 'z';
            } else if (isupper(plainLetter)) {
                a = 'A';
                z = 'Z';
            }

            if (plainLetter - key >= a) {
                output += plainLetter - key;
            } else {
                output += ((plainLetter - key + z) - (a-1))  ;
            }
        }
    }
}

int main(int argc, char** argv)
{
    std::string inputFileName;
    std::string outputFileName;
    std::string input;
    int mode; //0 is encrypt, 1 is decrypt
    int key;

    if (argc != 5) {
        std::cout << "Incorrect number of arguments given";
        return 1;
    }
    
    if(strcmp(argv[1], "-e")) {
        mode = 0;
    } else if (strcmp(argv[1],"-d")) {
        mode = 1;
    }
    
    key = int(argv[2][0] - '0');
    inputFileName = argv[3];
    outputFileName = argv[4];
    
    
    std::ifstream inputStream(inputFileName);
    std::ofstream outputStream(outputFileName);
    
    std::getline(inputStream, input);
   
    std::string output;
    if(mode) {
        encrypt(key, input, output);
    } else {
        decrypt(key, input, output);
    }

    outputStream << output;
    
    return 0;
}