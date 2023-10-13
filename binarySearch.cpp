#include <iostream>
#include <vector>


int binarySearch(std::vector<int> givenVector, int givenValue){
    int size = givenVector.size(); 
    int begin = 0; 
    int end  = size - 1; 
    

    while(begin <= end){
        int middle = begin + (end - begin)/2; 
        int value = givenVector[middle]; 

        if(value < givenValue){
            begin = middle + 1;
        } else if (value > givenValue){
            end = middle - 1;
        } else { 
            return middle; 
        }
    }

    return -1; 


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



int main(){
    std::vector<int> myVec = {1,2,3,4,5,6,7}; 
    std::cout << "Value '3' found in index: " << binarySearch(myVec, 2) << std::endl; 

}
