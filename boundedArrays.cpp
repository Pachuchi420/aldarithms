#include <iostream>

int main(){ 
    int myarr[3];

    for(int i = 0; i < sizeof(myarr) - 1; i++){ 
        myarr[i] = 3 + i;
    }

    for(int element : myarr){
        std::cout << element << " ";
    } 
    std::cout << std::endl;

    // We can't add more slots! That's where unbounded arrays come into play!
}




