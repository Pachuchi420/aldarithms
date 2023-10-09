#include <iostream> 
#include <vector>


template<typename K, typename V>  
struct node{
    K key_;
    V value_; 
    node* next; 

    node(K givenKey,V givenValue){
        key_ = givenKey;
        value_ = givenValue; 
        next = nullptr;
    }

    V value(){
        return value_;
    }

    K key(){
        return key_;
    }
};

template<typename K, typename V> 
class simpleLinkedList{
    private: 
    node<K,V>* head; 
    

    public: 
    simpleLinkedList(){
        head = nullptr;
    }


    V first(){
        if(head == nullptr){
            std::cerr << "Error list is empty!" << std::endl;
            return; 
        } else { 
            return head->value();
        }
        
    }

    V last(){
        if(head == nullptr){
            std::cerr << "Error list is empty!" << std::endl;
            return; 
        } else { 
            node<K,V>* current = head; 
            while(current->next != nullptr){
                current = current->next; 
            }
            return current->value();
        }
    }


    void pushBack(K givenKey,V givenValue){ 
        node<K,V>* newNode = new node<K,V>(givenKey,givenValue); 
        if(head == nullptr){ 
            head = newNode; 
        } else { 
            node<K,V>* current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
        }
    }


    void pushFront(K givenKey,V givenValue){
        node<K,V>* newNode = new node<K,V>(givenKey, givenValue); 
         if(head == nullptr){ 
            head = newNode; 
        } else { 
            newNode->next = head; 
            head = newNode;
        }
    }

    void print(){
        if(head == nullptr){
            std::cerr << "Error list is empty!" << std::endl;
            return; 
        } else {
            node<K,V>* current = head;
            while(current != nullptr){
                std::cout << "[" <<current->key() << " : " << current->value() << "]";
                if(current->next != nullptr){
                    std::cout << " -> ";
                }
                current = current->next;
            }
            std::cout << std::endl;
            
        }
    }

    void popFront(){
        if(head == nullptr){
            std::cerr << "Error list is empty!" << std::endl;
            return; 
        } else {
            node<K,V>* current = head; 
            head = current->next;
            delete current;
        }
    }


    void popBack(){
        
        if(head == nullptr){
            std::cerr << "Error list is empty!" << std::endl;
            return; 
        } else if(head->next == nullptr){
            delete head; 
            head = nullptr;
        } else {
            node<K,V>* current = head;
            while(current->next->next != nullptr){
                current = current->next;
            }
            
            delete current->next;
            current->next = nullptr;
        }
    }

    bool findKey(K givenKey){ 
        if(head == nullptr){ 
            std::cerr << "Error list is empty!" << std::endl;
            return false; 
        } else { 
            node<K,V>* current = head; 
            while (current != nullptr){
                if(current->key() == givenKey){ 
                    return true;
                }
                current = current->next;
            }
            return false;
        }
    }

    
    void remove(V givenValue){ 
        if(head == nullptr){ 
            std::cerr << "Error list is empty!" << std::endl;
            return; 
        } else { 
            // If value is in first node
            if (head->value() == givenValue){ 
                popFront(); 
            } else {
                node<K,V>* current = head; 
                node<K,V>* previous = nullptr;
                
                while (current != nullptr && current->value() != givenValue) {
                    previous = current;
                    current = current->next;
                }

                if(current->next == nullptr && current->value() == givenValue){
                    popBack();
                } else if (current->value() == givenValue){ 
                    previous->next = current->next;
                    delete current;
                } else { 
                     std::cerr << "Value not found!" << std::endl;
                    return; 
                }
            }
        }
    }

    void removeByKey(const K& givenKey) {
    if (head == nullptr) {
        // List is empty
        return;
    }
    
    if (head->key() == givenKey) {
        // If the head node is the one to be deleted
        node<K,V>* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    node<K,V>* current = head;
    node<K,V>* previous = nullptr;

    while (current != nullptr && current->key() != givenKey) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        // Key was not found in the list
        return;
    }

    // Adjust previous node's next to skip current node
    previous->next = current->next;
    delete current; // Delete the current node
    }


    bool isEmpty(){ 
        return head == nullptr;
    }
};

template<typename K, typename V> 
struct entry{
    simpleLinkedList<K,V> linkedList;
};



template<typename K, typename V>
class hashTable{
    private: 
    std::vector<entry<K,V>> table;
    int size; 
    int (*hashFunction)(const K&); 


    public: 

    hashTable(int givenSize, K (*givenHashFunction)(const K&)){
        table.resize(givenSize);
        hashFunction = givenHashFunction;
        size = givenSize;
    }

    void insert(const K& givenKey, const V& givenValue){ 
        int index = hashFunction(givenKey) % size; 
        table[index].linkedList.pushBack(givenKey, givenValue); 
    }


    void remove(const K& givenKey){ 
        int index = hashFunction(givenKey) % size; 
        if(table[index].linkedList.isEmpty()){
            std::cerr << "No entries at this index" << std::endl;
            return;
        } else if(table[index].linkedList.findKey(givenKey) == false){
            std::cerr << "Key not found!" << std::endl;
            return;
        } else {
            table[index].linkedList.removeByKey(givenKey);
        }
    }

    void print() {
            for (int i = 0; i < size; ++i) {
                std::cout << "Slot " << i << ": ";
                
                if (table[i].linkedList.isEmpty()) {
                    std::cout << "Empty" << std::endl;
                } else {
                    table[i].linkedList.print();  // Use the print function of your simpleLinkedList class
                }
            }
            std::cout << std::endl;
    }

};  


int hashFunc(const int& key) {
    return key % 10;  // A simple modulo-based hash for this example.
}




int main() {
    hashTable<int, std::string> myHashTable(4, hashFunc); 

    myHashTable.insert(10, "Zero"); 
    myHashTable.insert(10, "Collision on Zero");
    myHashTable.insert(12, "Two");
    myHashTable.insert(22, "Collision on Two");
    myHashTable.print();
    myHashTable.remove(12);
    myHashTable.print();


}


