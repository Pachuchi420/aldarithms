#include <iostream> 


template<typename T> 
class boundedFifo{ 
    private: 
        T* array; 
        size_t maxSize;
        size_t head; 
        size_t tail;

    public: 
        // Constructor 
        boundedFifo(size_t size){ 
            maxSize = size; 
            head = 0; 
            tail = 0; 
            array = new T[maxSize + 1]; 
        }

        // Destructor
        ~boundedFifo(){ 
            delete[] array; 
        }

        // Check if empty
        bool isEmpty() { 
            return head == tail; 
        }

        // Return first element 
        T first(){
            assert(!isEmpty()); 
            return array[head]; 
        }

        // Return size of FIFO 
        size_t size(){ 
            return (tail - head + maxSize + 1) % (maxSize + 1);
        }

        // Pushback element 
        void pushBack(T givenValue){ 
            assert(size() < maxSize);
            array[tail] = givenValue; 
            tail = (tail + 1) % (maxSize + 1); 
        }

        // popFront
        void popFront(){ 
            assert(!isEmpty());
            head = (head + 1) % (maxSize + 1); 
        }

        void print(){ 
            size_t current = head;
            std::cout << "[";
            while(current != tail){ 
                std::cout << array[current];
                if (current+1 != tail){ 
                    std::cout << " ";
                }
                
                current = (current + 1) % (maxSize + 1); 
            }
            std::cout << "]" << std::endl;
        }
}; 


int main(){ 
    boundedFifo<int> myfifo(5);

    myfifo.pushBack(1);
    myfifo.pushBack(2);
    myfifo.pushBack(3);
    myfifo.pushBack(4);
    myfifo.pushBack(5);

    myfifo.print(); 

    myfifo.popFront(); 
    myfifo.print();


}