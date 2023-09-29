#include <iostream> 

template<typename T>
struct node{ 
    node* next; 
    T value_;

    node(T givenValue){ 
        next = nullptr;
        value_ = givenValue;
    }

    T value(){ 
        return value_;
    }  
};


template<typename T> 
class simpledLinkedList{
    private:
        node<T>* head; 
    public: 
        // Constructor for list   
        simpledLinkedList(){
            head = nullptr;
        }

        // Show first element : mantains O(1) complexity
        T first(){ 
            if(head->next == nullptr){
                std::cerr << "List is empty!" << std::endl;
                return -1; 
            }
            return head->value();
        }

        // Show first element : has O(n) complexity
        T last(){ 
            if(head == nullptr){
                std::cerr << "List is empty!" << std::endl;
                return -1; 
            }

            node<T>* current = head; 
            while(current->next != nullptr){
                current = current->next; 
            }
            return current->value; 
        }

        // Prints elements : mantains a O(n) complexity
        void print(){
            node<T>* tempNode = head;
            while(tempNode != nullptr){ 
                std::cout << tempNode->value();
                if(tempNode->next != nullptr){
                    std::cout << " <-> " ;
                }
                tempNode = tempNode->next;
            }
            std::cout << std::endl;
        }

        // Adds elements to the front : mantains O(1) complexity
        void pushFront(T givenValue){ 
            node<T>* newNode = new node<T>(givenValue); 

            if(head == nullptr){
                head = newNode;
            } else  
                newNode->next = head; 
                head = newNode;
        }

        // Adds elements to the back : has an O(n) complexity
        void pushBack(T givenValue){
            node<T>* newNode = new node<T>(givenValue);
            if(head == nullptr){ 
                head = newNode;
            } else { 
                node<T>* current = head;
                while(current->next != nullptr){ 
                    current = current->next;
                }
            current->next = newNode;
            }
        }

        // Removes first element : mantains O(1) complexity
        void popFront(){
            if(head == nullptr){ 
                std::cerr << "List is empty can't popFront!" << std::endl;
                return;
            } else { 
                node<T>* oldHead = head; 
                head = head->next;
                delete oldHead;
            }
        }

        // Removes last element : has a O(n) complexity
        void popBack(){
            if(head == nullptr){ 
                std::cerr << "List is empty can't popBack!" << std::endl;
                return;
            }

            if(head->next == nullptr){ 
                delete head; 
                head = nullptr; 
                return;
            }

            node<T>* current = head;
            while(current->next->next != nullptr){ 
                current = current->next; 
            }
            delete current->next;
            current->next = nullptr;
            
        }

        // Find value within list : has O(n) complexity
        void findValue(T givenValue){ 
            node<T>* current = head; 
            int counter = 1;

            while(current->next != nullptr){ 
                counter++;
                if(current->value_ == givenValue){ 
                    std::cout << "Value " << givenValue <<" is found on node " << counter << std::endl;
                    return;
                }
            }
        }

        // Concatenates lists : has O(n) complexity
        void concatenate(simpledLinkedList<T>& listToAdd){
            if(head == nullptr){ 
                listToAdd.print();
            } else { 
                node<T>* current = head;
                while(current->next != nullptr){
                    current = current->next;
                }
                current->next = listToAdd.head; 
                listToAdd.head = nullptr;
                }
            }

        // Remove element in list : has O(n) complexity
        void remove(T givenValue){
            if(head == nullptr){
                std::cerr << "Can't remove any node, list empty!" << std::endl;
            } else { 

                // If first element is to be removed 
                if(head->value_ == givenValue){ 
                    popFront();
                }

                // Find value
                node<T>* current = head; 
                node<T>* prev = nullptr;
                while(current != nullptr && current->value_ != givenValue){ 
                    prev = current; 
                    current = current->next;
                }


                if(current != nullptr){ 
                    // If element last
                    if(current->next == nullptr){
                        popBack();
                        return; 
                    }

                    // If middle value 
                    prev->next = current->next;
                    delete current; 

                }

            }
        }

};






int main(){ 
    simpledLinkedList<int> list1; 
    list1.pushFront(4);
    list1.pushFront(3);
    list1.pushFront(2);
    list1.pushFront(1);
    list1.print();

    simpledLinkedList<int> list2; 
    list2.pushFront(8);
    list2.pushFront(7);
    list2.pushFront(6);
    list2.pushFront(5);
    list2.print();

    list1.concatenate(list2);

    list1.print();
    list1.remove(4);
    list1.print();
    

    

} 