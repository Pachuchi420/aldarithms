#include <iostream> 
#include <vector>

template<typename KEY, typename VALUE> 
struct entry{
    KEY key; 
    VALUE value; 
    bool empty = true;

    bool isEmpty(){ 
        return empty; 
    }

    void setEmpty(){
        empty = true;
    }

    void setNotEmpty(){ 
        empty = false;
    }

};

template<typename KEY, typename VALUE> 
class linearProbing{
    private: 
    std::vector<entry<KEY,VALUE>> table;
    int size; 
    int (*hashFunc)(const KEY&); 

    public: 
    // Constructor
    linearProbing(int givenSize, KEY (*givenHashFunc)(const KEY&)){
        this->table = std::vector<entry<KEY,VALUE>>(givenSize); 
        this->hashFunc = givenHashFunc;
        this->size = givenSize; 
    }

    
    void insert(const KEY& givenKey, const VALUE& givenValue){ 
        KEY i; 
        for(i = hashFunc(givenKey); i <= !table[i].isEmpty() ; i++){ 
            assert(i <= size - 1); 
        }
        
        table[i].key = givenKey;
        table[i].value = givenValue; 
        table[i].setNotEmpty(); 
    }

    VALUE* find(const KEY& givenKey){ 
        KEY i; 
        for(i = hashFunc(givenKey) ; !table[i].isEmpty() && givenKey != table[i].key ; i++ ); 

        if(table[i].isEmpty()){ 
            std::cerr << "Key " << givenKey << "not found in the table." << std::endl;
            return nullptr;
        }
        
        std::cout << "Value for key '" << givenKey << "' is: " << table[i].value << std::endl; 
        return &table[i].value;
    }

    void remove(const KEY& givenKey){ 
        KEY i; 
        for(i = hashFunc(givenKey) ; !table[i].isEmpty() && givenKey != table[i].key ; i++); 

        // If not found
        if(table[i].isEmpty()){ 
            std::cerr << "Key '" << givenKey << "' not found in the table." << std::endl;
            return; 
        } 

        // If found set empty to true
        table[i].setEmpty(); 


        int j = i + 1; 
        while (!table[j].isEmpty()){ 
                        if (hashFunc(table[j].key) <= i) {
                table[i] = table[j];
                table[i].isEmpty() = false;
                table[j].isEmpty() = true;
                i = j;
            }
            j++;
        }



    }
    
    void print(){ 
        for(int i = 0 ; i <= size - 1 ; i++){ 
            std::cout << i << ".Slot:  " << "[" << table[i].key << ", " << table[i].value << "]" << std::endl;
        }
        return;
    }




}; 



// Example hash function
int hashFunction(const int& key) {
    return key % 100; // Simple modulo hash
}


int main(){ 
    linearProbing<int, int> myTable(100, hashFunction);
    int j = 0; 
    for(int i = 0; i <= 99 ; i++){ 
        myTable.insert(100 + j, i);
        j++;
    }
    myTable.print();


}