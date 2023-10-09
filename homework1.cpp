#include <iostream> 
#include <vector> 
#include <cmath>


// Complexity: logn^2
void exercise1(int n){
    int a = 1; 
    int b = 1; 

    while (a < n){ 
        a = a + a; 
        b = 1; 
        while(b < n){ 
            b =  b + b ;
        }
    }
    return;
}

// Complexity : n^2logn
void exercise2(int n){ 
    int a = 1; 
    int b = 1; 
    int c = 1; 

    while(a < n){
        a++;
        while(b < n){ 
            b++; 
            while(c < n) { 
                c = c + c;
            }
        }
    }
}



// Complexity : 2^n
int exercise3(int n){ 
    if (n == 0) return 1;

    return 2 * exercise3(n-1);   
}

// Complexity : n^n 
void exercise4(int n, int depth = 0) {
    if (depth == n) {
        return;
    }

    for (int i = 0; i < n; ++i) {
        exercise4(n, depth + 1);
    }
}



int findMissingNumber(std::vector<int>& givenVector){
    // We do +1 because one number is missing
    int size = givenVector.size() + 1;

    // Get binary max size
    int binarySize = log2(size);

    int leftSide = 0; 
    int rightSide = size - 2; 

    int missing = 0; 

    for(int bit = binarySize - 1 ; bit >= 0 ; bit--){
        int zeros = 0; 
        int ones = 0; 

        for(int i = leftSide; i <= rightSide; i++){
            if ((givenVector[i] & (1 << bit)) == 0){
                zeros++;
            } else { 
                ones++;
            }
        }

        if (zeros < (1 << bit)){ 
            missing |= (0 << bit);  // The missing number has this bit set as 0
            rightSide = leftSide + zeros - 1;  // Update the range to focus on the lower half
        } else { 
            missing |= (1 << bit);  // The missing number has this bit set as 1
            leftSide = leftSide + zeros;  // Update the range to focus on the upper half
        }
    }

    return missing;
}


int karatsuba(int a, int b) {
    if (a < 10 || b < 10) return a * b;

    int size = std::max((int)log10(a) + 1, (int)log10(b) + 1);
    int half = size / 2;

    int power = pow(10, half);

    int leftA = a / power;
    int rightA = a % power;
    int leftB = b / power;
    int rightB = b % power;

    int c11 = karatsuba(leftA, leftB);
    int c00 = karatsuba(rightA, rightB);
    int c0110 = karatsuba(leftA + rightA, leftB + rightB);

    return c11 * pow(10, 2 * half) + (c0110 - c11 - c00) * pow(10, half) + c00;
}

int main(){ 
    std::cout << "27 x 32 = " << karatsuba(27,32) << std::endl;  // Should output 864
}
