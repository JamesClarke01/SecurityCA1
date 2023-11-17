#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

std::map<char, float> createAlphabetMap() {
    //Function creates a map with A-Z as keys, and values initialised to 0

    std::map<char, float> alphabetMap;
    
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        alphabetMap[ch] = 0;
    }

    return alphabetMap;
}

bool greater(std::pair<char, float>& a, std::pair<char, float>& b) 
{ 
    return a.second > b.second; 
} 


int main(void) {
    std::string cipher = "UZQSOVUOHXMOPVGPOZPEVSGZWSZOPFPESXUDBMETSXAIZVUEPHZHMDZSHZOWSFPAPPDTSVPQUZWYMXUZUHSXEPYEPOPDZSZUFPOMBZWPFUPZHMDJUDTMOHMQ";
    int i;

    std::map<char, float> letterFreq = createAlphabetMap();
    
    char englishLetterFrequency[] = {'E','T','A','O','I','N','S','H','R','L','D','C','U','M','W','F','G','Y','P','B','V','K','J','X','Q','Z'}; 
    
    std::map<char, char> legend;

    //Count how many of each letters are in ciphertext
    for(i = 0; i < cipher.length(); i++) {
        letterFreq[cipher[i]]++;  
    }
    
    //Calculate frequencies
    for (std::pair<char, float> element: letterFreq) {        
        element.second = (element.second/cipher.length())*100;
    }

    //Copy the map into a vector
    std::vector<std::pair<char, float>> freqVector(letterFreq.begin(), letterFreq.end());
    
    //Sort the vector by value descending
    std::sort(freqVector.begin(), freqVector.end(), greater);

    //Create translation legend
    for(i = 0; i < freqVector.size(); i++) {    
        legend[freqVector[i].first] = englishLetterFrequency[i];       
    }
    
    //Translate message
    for(i = 0; i < cipher.length(); i++) {
        std::cout << legend[cipher[i]];
    }

    return 0;
}

