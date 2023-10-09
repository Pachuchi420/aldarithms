#include <iostream>

// Aufgabe 2
template<typename T> 
struct node{
    node* next; 
    T data; 

    node(T givenData){ 
        data = givenData; 
        next = nullptr; 
    }
    
    T value(){
        return data;
    }
};

template<typename T>
class stack{
    private:
    node<T>* head; 

    public: 
    stack(){
        head = nullptr;
    }

    void pushFront(T givenData){ 
        node<T>* newNode = new node<T>(givenData); 

        // Base case
        if (head == nullptr){
            head = newNode; 
        } else {
            // Elements already present
            newNode->next = head;
            head = newNode;
        }
    }


    void pushBack(T givenData){
        node<T>* newNode = new node<T>(givenData); 
        node<T>* travelNode = head; 

        // Base case 
        if (travelNode == nullptr){
            travelNode = newNode; 
        } else {
            while(travelNode->next != nullptr){
                travelNode = travelNode->next;
            }
            travelNode->next = newNode;
        }
    }

    void popFront(){
        
        // Base Case 
        if (head == nullptr){
            std::cout << "Not possible, stack empty" << std::endl; 
            return; 
        } else {
            node<T>* oldHead = head; 
            head = head->next; 
            delete oldHead; 
        }
    }

    // We cannot have the functions pushBack and popBack as it requires O(n) complexity to travel through the whole list, therefore a DLL is needed!

    

    void print(){
        node<T>* tempNode = head;
        std::cout << "["; 
        while(tempNode != nullptr){
            
            std::cout << tempNode->value() ;
            if(tempNode->next != nullptr){
                std::cout << ' '; 
            }
            tempNode = tempNode->next;
        }
        std::cout << "]" << std::endl;
    }
}; 


// Aufgabe 3
template<typename T>
class queue {
    private: 
    T* array; 
    int capacity; 
    int currentSize; 

       void resize(int newCapacity){
        T* newArray = new T[newCapacity];
        for(int i = 0; i <= currentSize - 1; i++){
            newArray[i] = array[i];
        }
        delete[] array; 
        array = newArray;
        capacity = newCapacity;
       }

    public: 
    queue(int givenCapacity) {
        capacity = givenCapacity;
        currentSize = 0; 
        array = new T[capacity];
    }

    void pushBack(T givenData) {
        if(currentSize == capacity) { // If array full
            resize(2 * capacity);
        }

        // If not full
        array[currentSize++] = givenData;
    }

    void popFront() {
        if(currentSize == 0) {
            std::cerr << "popFront not possible as array is empty!"; 
            return;
        }
        currentSize--;
        if (currentSize <= capacity / 4 && capacity > 1) {
            resize(capacity / 2);
        }
    }

    void print() {
        std::cout << '[';
        for(int i = 0; i <= currentSize -1 ; i++) {
            std::cout << array[i];
            if(i < currentSize - 1) {
                std::cout << ' ';
            }
        }
        std::cout << ']' << std::endl;
    }
};

    




int main(){
    std::cout << "STACK: " << std::endl; 
    stack<int> myStack; 
    myStack.pushFront(2);
    myStack.pushFront(3);
    myStack.pushFront(4);
    myStack.pushFront(5);
    myStack.pushFront(6);
    myStack.print();
    myStack.pushBack(69);
    myStack.print();


    std::cout << "\nQUEUE: " << std::endl; 
    queue<int> myQueue(5); 
    myQueue.pushBack(1);
    myQueue.pushBack(2);
    myQueue.pushBack(3);
    myQueue.pushBack(4);
    myQueue.pushBack(5);
    myQueue.print();
    myQueue.pushBack(6);
    myQueue.print();
}