#include <iostream>
#include <math.h>

int millerRabin(int n) {
    int k, q, a;

    k = 0;
    q = n-1;
    
    //1. Finding k and q where k > 0, q is odd, so that: (n-1)==(2^k)*q)
    while (q % 2 == 0) {  //keep interating until q is not even
        k++;
        q = (n-1)/pow(2, k);
    }

    //2. Select a random integer a, 1 < a < n-1
    a = rand() % (n-3) + 2;
    
    //3. if (a^q) % n == 1 then return "inconclusive"
    if (int(pow(a,q)) % n == 1) {
        return 0;    
    }

    //4. for j=0 to k-1 do
    for(int j=0; j<k; j++) {
        if(int(pow(a, (pow(2, j) * q))) % n == n-1) {  //5. if a^(2^j)*q mod n == n-1
            return 0;
        }  
    }

    //6. return "composite"
    return 1;
}


int main(void)
{
    int input;

    std::cout << "Please enter a number: ";
    std::cin >> input;
    
    
    if(millerRabin(input) == 0) {
        std::cout << "Prime";
    } else {
        std::cout << "Composite";
    }
       
}
