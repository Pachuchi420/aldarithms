#include <iostream>
#include <vector> 
#include <random>


template<typename T>
std::vector<T> createVector(int size){
    std::vector<T> vec;
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<T> distrib(1, 9);  

    for(int i = 0; i < size; ++i) {
        vec.push_back(distrib(gen));  
    }

    return vec; 
}


template<typename T>
void print(std::vector<T> givenVec){
    std::cout << "[";
    for (int i = 0 ; i <= givenVec.size() - 1 ; i++){ 
        std::cout << givenVec[i]; 
        if (i < givenVec.size() - 1){ 
            std::cout << ", ";
        }
    } 
    std::cout << "]" << std::endl; 
}


void insertionSort(std::vector<int> givenVec){ 
    for(int i = 1; i < givenVec.size() - 1 ; i++){ 
        int temp = givenVec[i];
        int left = i - 1; 
        
        if(left >= 0 && givenVec[left] > temp){
            givenVec[left + 1] = givenVec[left]; 
            left--;
        }
        givenVec[left + 1] = temp;
    }

    print(givenVec);
}



int main(){ 
    std::vector<int> myVector = createVector<int>(10); 
    print(myVector);
    insertionSort(myVector);

}