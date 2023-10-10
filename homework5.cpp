#include <iostream> 
#include <vector> 


std::vector<int> sortWarmup(std::vector<int>& vec1, std::vector<int>& vec2){
    std::vector<int> result(vec1.size() + vec2.size());
    for(int i = 0; i < vec1.size()-1; i++){
        result[i] = vec1[i];
    }

    for(int i = 0; i < vec2.size(); i++){
        for(int j = 0; j < result.size(); j++){
            if(vec2[i] <= result[j]){
                int temp = vec2[i];
                for(int k = j; k < result.size(); k++){
                    int nextTemp = result[k];
                    result[k] = temp;
                    temp = nextTemp;
                }
                break;
            }
        }
    } 

    return result;
 
}


void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}


int partition(std::vector<int>& vec, int begin, int end){
    int pivot = vec[end];
    int i = begin - 1; 
    for(int j = begin; j <= end - 1; j++){
        if(vec[j] < pivot){ 
            i++; 
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i+1], vec[end]);
    return i + 1; 
}   


void quickSort(std::vector<int>& vec, int begin, int end){
    if(begin < end){ 
        int pivotIndex = partition(vec, begin, end); 
        quickSort(vec, begin, pivotIndex - 1); // For left side
        quickSort(vec, pivotIndex + 1, end); // For right side
    }
}

std::vector<int> merge(std::vector<int>& vec1, std::vector<int>& vec2){
    int size1 = vec1.size(); 
    int size2 = vec2.size(); 

    std::vector<int> result(size1 + size2);

    int i = 0 , j = 0, k = 0; 

    while(i < size1 && j < size2){ 
        if(vec1[i] <= vec2[j]){
            result[k++] = vec1[i++];
        } else { 
            result[k++] = vec2[j++];
        }
    }

    return result;
}



void print(std::vector<int>& vec){
    for(int element : vec){
        std::cout << element;
    }
    std::cout << std::endl;
}






int main(){
    std::vector<int> vec1 = {1,2,3,4,5};
    std::vector<int> vec2 = {4,1,2};
    quickSort(vec2, 0, vec2.size() - 1 ); 
    print(vec2);
    std::vector<int> res2 = merge(vec1, vec2);
    print(res2);
}