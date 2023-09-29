#include <iostream>

template<typename T>
struct node{

        T data;
        node<T>* next; 
        node<T>* prev;

        node(T givenData){ 
            data = givenData;
            next = nullptr;
            prev = nullptr;
        }

        T giveData(){
            return data;
        }
};  


template<typename T> 
class doubleLinkedList{ 
    private: 
        node<T>* head; 
        node<T>* tail;
    
    public:
        // Constructor
        doubleLinkedList(){
            head = nullptr;
            tail = nullptr;
        }

        // Takes O(1) complexity time
        void first(){ 
            std::cout << "First element is: " << head->data << std::endl;
        }

        // Takes O(1) complexity time
        void last(){ 
            std::cout << "Last element is: " << tail->data << std::endl;
        }

        // Takes O(1) complexity time
        void pushFront(T data){
            node<T>* newNode = new node<T>(data);

            if(head == nullptr){
                head = newNode; 
                tail = newNode;
            } else { 
                newNode->next = head; 
                head->prev = newNode; 
                head = newNode;
            }
        }

        // Takes O(1) complexity time
        void pushBack(T data){ 
            node<T>* newNode = new node<int>(data);

            if(head == nullptr){ 
                head = newNode; 
                tail = newNode;
            } else { 
                tail->next = newNode; 
                newNode->prev = tail; 
                tail = newNode;
            }
        }

        // Takes O(1) complexity time
        void popFront(){ 
            if(head == nullptr){
                std::cerr << "No elements to be removed. ERROR" << std::endl;
            } else { 
                node<T>* oldHead = head;
                head = head->next;
            
                if(head != nullptr){ 
                    head->prev = nullptr;
                } else { 
                    head = nullptr;
                }

                delete oldHead;
            }
        }

        // Takes O(1) complexity time
        void popBack(){ 
            if(tail == nullptr){
                std::cerr << "No elements to be removed. ERROR" << std::endl;
            } else { 
                node<T>* oldTail = tail;
                tail = tail->prev;
            
                if(tail != nullptr){ 
                    tail->next = nullptr;
                } else { 
                    head = nullptr;
                }

                delete oldTail;
            }
        }

        // Takes O(n) complexity time
        void print(){ 
            node<T>* tempNode = head;

            while (tempNode != nullptr){ 
                std::cout << tempNode->data; 
                if(tempNode->next != nullptr){
                    std::cout << " <-> "; 
                }
                tempNode = tempNode->next; 
            }

            std::cout << std::endl;

        }

        // Takes O(n) complexity time
        void findValue(T given){ 
            node<T>* tempNode = head; 
            int position = 1; 

            while (tempNode != nullptr){ 
                if(given == tempNode->giveData()){
                    std::cout << "Value " << given << " found in node: " << position << std::endl; 
                }
                position++;
                tempNode = tempNode->next; 
            }

        }

        // Takes O(1) complexity time
        void concatenate(doubleLinkedList<T>& listToAdd){
            // Check if list our first list is empty
            if (this->head == nullptr){ 
                this->head = listToAdd.head;
                this->tail = listToAdd.tail;
                return;
            }


            // Check if our second list is empty
            if(listToAdd.head == nullptr){
                return;
            }

            
            // Case 1
            this->tail->next = listToAdd.head;

            // Case 2
            listToAdd.head->prev = this->tail;

            // Case 3
            this->tail = listToAdd.tail;
        }


        void remove(T givenValue){
            node<T>* tempNode = head;

            while(tempNode != nullptr){
                if(tempNode->giveData() == givenValue){
                    // First element is to be removed
                    if(tempNode->prev == nullptr){
                        popFront();
                        return;
                    }

                    // Last element is to be removed 
                    else if(tempNode->next == nullptr){
                        popBack();
                        return;
                    }


                    // Middle element is to be removed
                    else { 
                        tempNode->next->prev = tempNode->prev;
                        tempNode->prev->next = tempNode->next;
                        delete tempNode; 
                        return;

                    }

                }
                tempNode = tempNode->next;
            }
            
        }


};



int main(){ 
    doubleLinkedList<int> myList1;
    myList1.pushFront(1);
    myList1.pushFront(2);
    myList1.pushFront(3);
    myList1.pushFront(4);
    myList1.pushFront(5);
    myList1.pushBack(20);
    myList1.print();
    myList1.remove(3);
    myList1.print();


    

    

    
    }