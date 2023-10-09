#include <iostream> 
#include <vector> 
#include <random>


std::vector<int> createVector(int size){ 
    std::vector<int> vec;
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> distrib(1, 9); 

    for(int i = 0 ; i < size ; i++){ 
        vec.push_back(distrib(gen));
    }

    return vec;
}


void print(const std::vector<int>& givenVector){ 
    std::cout << "["; 
    for(int i = 0 ; i <= givenVector.size()-1 ; i++){ 
        std::cout << givenVector[i];
        if (i < givenVector.size() - 1){ 
            std::cout << ", "; 
        }
    }
    std::cout << "]" << std::endl;
}


// This is O(n^2) worst and average time, but O(n) in best case
void insertionSort (std::vector<int>& givenVector){ 
    for(int i = 1 ; i < givenVector.size() - 1 ; i++){
        int temp = givenVector[i]; 
        int left = i - 1;

        while(left >= 0 && givenVector[left] > temp){ 
            givenVector[left + 1] = givenVector[left]; 
            left--;
        }
        givenVector[left + 1] = temp;
    }
}


int main(){
    std::vector<int> myVec = createVector(10);
    print(myVec);
    insertionSort(myVec);
    print(myVec);
}