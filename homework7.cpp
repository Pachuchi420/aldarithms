#include <iostream>
#include <vector>

// Helper function to recursively convert sorted vector into implicit form
void convertToImplicit(const std::vector<int>& sorted, int start, int end,
                       std::vector<int>& result, int index) {
    if (start > end) return;

    int mid = (start + end) / 2;
    result[index] = sorted[mid];

    convertToImplicit(sorted, start, mid - 1, result, 2*index + 1);
    convertToImplicit(sorted, mid + 1, end, result, 2*index + 2);
}

std::vector<int> implicitForm(const std::vector<int>& sorted) {
    int n = sorted.size();
    std::vector<int> result(2*n-1, -1);  // Initialize to -1, assuming no negative numbers in the input
    convertToImplicit(sorted, 0, n - 1, result, 0);
    return result;
}

void print(const std::vector<int>& vec) {
    for (int val : vec) {
        if (val != -1) {
            std::cout << val << " ";
        }
    }
    std::cout << std::endl;
}

// O(k + logn)
std::pair<int, int> firstAndLast(std::vector<int> givenVector, int givenValue){
    int size = givenVector.size(); 
    int begin = 0; 
    int end  = size - 1; 
    int middle;
    

    while(begin <= end){
        middle = begin + (end - begin)/2; 
        int value = givenVector[middle]; 

        if(value < givenValue){
            begin = middle + 1;
        } else if (value > givenValue){
            end = middle - 1;
        } else { 
            break;
        }
    }

    if(givenVector[middle] != givenValue){
        std::cerr << "Value '" << givenValue << "' not found in vector!" << std::endl; 
        return {-1,-1}; 
    }

    int firstOccurrence = middle;
    while(firstOccurrence > 0 && givenVector[firstOccurrence - 1] == givenValue){
        firstOccurrence--;
    }

    int lastOccurrence = middle; 
    while (lastOccurrence < size && givenVector[lastOccurrence + 1] == givenValue){
        lastOccurrence++; 
    }

    return{firstOccurrence, lastOccurrence}; 



}


int firstOccurrence(std::vector<int> givenVector, int givenValue){
    int size = givenVector.size(); 
    int begin = 0; 
    int end  = size - 1; 
    int res = -1;
    

    while(begin <= end){
        int middle = begin + (end - begin)/2; 
        int value = givenVector[middle]; 

        if(value == givenValue){
            res = middle;
            end = middle - 1; 
        } else if (value < givenValue){
            begin = middle + 1;
        } else { 
            end = middle - 1; 
        }
    }
    return res; 
}


int lastOccurrence(std::vector<int> givenVector, int givenValue){
    int size = givenVector.size(); 
    int begin = 0; 
    int end  = size - 1; 
    int res = -1;
    

    while(begin <= end){
        int middle = begin + (end - begin)/2; 
        int value = givenVector[middle]; 

        if(value == givenValue){
            res = middle;
            begin = middle + 1;
        } else if (value < givenValue){
            begin = middle + 1;
        } else { 
            end = middle - 1; 
        }
    }
    return res; 
}


int main() {
    std::vector<int> vec = {1,2,3,4,4,4,4,4,5,6,7,8}; // 3 and 7 
    std::pair<int,int> res = firstAndLast(vec, 4);
    std::cout << '(' << res.first << ',' << res.second << ')' << std::endl; 
    std::cout << '(' << firstOccurrence(vec, 4) << ',' << lastOccurrence(vec, 4) << ')' << std::endl; 




}






