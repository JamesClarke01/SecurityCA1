#include <iostream>
#include <fstream>
#include <string.h>
#include <string>

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

int main(int argc, char** argv) {
    int total;
    int r, c, k;
    int matrixRows;
    int matrixCols = 2;
    int** plainMatrix;
    int** resultMatrix;
    int keyMatrix[2][2];
    std::string key;
    std::string plainText;
    std::string encrypted;
    std::string inputFileName;
    std::string outputFileName;

    key = argv[1];
    inputFileName = argv[2];
    outputFileName = argv[3];

    std::ifstream inputStream(inputFileName);
    std::ofstream outputStream(outputFileName);

    std::getline(inputStream, plainText);

    //calculate what size matrix needed
    matrixRows = plainText.length() / 2;
    if (plainText.length() % 2 > 0) {  //if uneven amount
        matrixRows++;
    }
    
    //Init Plain Matrix
    plainMatrix = new int*[matrixRows];  //Create an array of int pointers
    for (r = 0; r < matrixRows; r++) {
        plainMatrix[r] = new int[matrixCols];  //Create an array of length 2 for each row
    }

    //Populate Plain Matrix
    k = 0;
    for(r = 0; r < matrixRows; r++) {
        for(c = 0; c < matrixCols; c++) {
            if (k < plainText.length()) {
                plainMatrix[r][c] = charToAlphaNum(plainText[k]);
            } else {  //fill with x if uneven plaintext word
                plainMatrix[r][c] = 'x';
            }
            k++;
        }
    }

    //Populate Key Matrix
    k = 0;
    for(r = 0; r < 2; r++) {
        for(c = 0; c < 2; c++) {
            keyMatrix[r][c] = charToAlphaNum(key[k]);
            k++;
        }
    }

    //Init Result Matrix
    resultMatrix = new int*[matrixRows];
    for (r = 0; r < matrixRows; r++) {
        resultMatrix[r] = new int[matrixCols];
    }

    //Encrypt
    for(r = 0; r < 2; r++) {
        for(c = 0; c < 2; c++) {
            //For each position in return matrix
            resultMatrix[r][c] = 0;

            for(k = 0; k < 2; k++) {
                resultMatrix[r][c] +=  keyMatrix[c][k] * plainMatrix[r][k];
            }

            resultMatrix[r][c] = resultMatrix[r][c] % 26;
        }
    }

    for(r = 0; r < 2; r++) {
        for(c = 0; c < 2; c++) {
            encrypted += alphaNumToChar(resultMatrix[r][c]);    
        }
    }

    outputStream << encrypted;
}