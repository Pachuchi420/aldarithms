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

void merge(std::vector<int> leftVec, std::vector<int> rightVec, std::vector<int>& givenVec){
    int leftSize = givenVec.size() / 2; 
    int rightSize = givenVec.size() - leftSize; 

    int i = 0; // Original vector
    int l = 0; // Left vector 
    int r = 0; // Right vector 

    while(l < leftSize && r < rightSize){ 
        if(leftVec[l] < rightVec[r]){ 
            givenVec[i] = leftVec[l];
            i++; 
            l++; 
        } else { 
            givenVec[i] = rightVec[r]; 
            i++;
            r++;
        }
    }

    while(l < leftSize){ 
        givenVec[i] = leftVec[l]; 
        i++; 
        l++; 
    }
    while(r < rightSize){
        givenVec[i] = rightVec[r]; 
        i++;
        r++;
    }

}


void mergeSort (std::vector<int>& givenVector){ 
    int length = givenVector.size(); 

    if(length <= 1) return; // If the vector is size of only 1 or less, we skip


    int middle = length / 2;
    std::vector<int> leftVec(middle);
    std::vector<int> rightVec(length - middle);

    int i = 0; // left vector
    int j = 0; // right vector

    for (; i < length; i++){ 
        if(i < middle){ 
            leftVec[i] = givenVector[i]; 
        } else { 
            rightVec[j] = givenVector[i]; 
            j++;
        }
    }

    mergeSort(leftVec); 
    mergeSort(rightVec); 
    merge(leftVec, rightVec, givenVector); 


}


int main(){
    std::vector<int> myVec = createVector(8);
    print(myVec);
    mergeSort(myVec);
    print(myVec);
}