#include <iostream>


template <typename T> 
class unboundedArray{
    private: 
        T* currentArray = nullptr;        // array of elements
        size_t currentSize = 0;           // current array size 
        size_t allocatedSize = 1;        // allocated array size

        void reallocate(size_t newAllocatedSize){ 
            T* newArray = new T[newAllocatedSize];
            for(size_t i = 0; i < currentSize; i++){ 
                newArray[i] = currentArray[i];
            }
            delete[] currentArray;
            currentArray = newArray; 
            allocatedSize = newAllocatedSize;
 
        }
    public: 


        unboundedArray(size_t size = 1){ 
            currentSize = 0; 
            allocatedSize = size; 
            currentArray = new T[allocatedSize]; 
        }

        T& operator[](size_t i){ 
            assert(i < currentSize); 
            return currentArray[i];
        }

        size_t size(){ 
            return currentSize;
        }

        void pushback(T givenValue){ 
            if(currentSize == allocatedSize){ 
                reallocate(2 * currentSize); 
            }
            currentArray[currentSize++] = givenValue;
        }


        void popback(){ 
            assert(currentSize > 0);
            currentSize--; 
            // Resize if spaces not used
            if(currentSize * 4 <= allocatedSize && currentSize > 0){ 
                reallocate(2 * currentSize); 
            }
        }

        ~unboundedArray(){ 
            delete[] currentArray;
        }

        void print(){
        std::cout << '[';
        for(int i = 0; i <= currentSize -1; i++) {
            std::cout << currentArray[i];
            if(i < currentSize - 1) {
                std::cout << ' ';
            }
        }
        std::cout << ']' << std::endl;
    }

}; 



int main(){ 
    unboundedArray<int> myarray(3);
    myarray.pushback(1);
    myarray.pushback(2);
    myarray.pushback(3);
    myarray.print();
    myarray.pushback(5);
    myarray.print();


}