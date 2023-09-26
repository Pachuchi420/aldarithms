#include <iostream>
#include <map> 
#include <list>
#include <cassert>


class directedGraph{
    private: 
        std::map<int, std::list<int>> adjList;
    public: 
        // Print adjacency list
        void print(){
            for(auto element : adjList){
                std::cout << "Node_" << element.first << " : ";

                for(int connectedNodes : element.second){
                    std::cout << connectedNodes << ' '; 
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        // Create node
        void createNode(int v){
            if (v > 0) {
                if(adjList.find(v) == adjList.end()) {
                    std::list<int> connectionList;
                    adjList[v] = connectionList;
                }
            } else { 
                std::cerr << "Value is negative or zero, not supported!" << std::endl;
            }

        }

        // Connect nodes
        void connect(int src, int goal){ 
            adjList[src].push_back(goal);
        }

        // Get size of graph
        int size(){
            return adjList.size();
        }

        // Get outdegree 
        int outdegree(int v){
            return adjList[v].size();
        }

        // Remove node 
        void remove(int v){

            // Remove nodes directed by v
            adjList[v].clear();

            // Remove nodes directed to v
            for(auto& element : adjList){
                element.second.remove(v);
            }

            // Delete node 
            adjList.erase(v);
        }


    bool empty(){
        return adjList.size() == 0;
    }
};

int getNullOutdegreeNode(directedGraph& graph){
    for(int i = 1 ; i <= graph.size() ; i++){
        if(graph.outdegree(i) == 0){
            return i;
        } 
    }
    return -1;
}

bool checkDAG(directedGraph& graph){ 
    directedGraph editableGraph = graph;
    int node = getNullOutdegreeNode(editableGraph);

    while(node != -1){
        editableGraph.remove(node);
        node = getNullOutdegreeNode(editableGraph);
    }

    if(editableGraph.empty()){ 
        std::cout << "Given graph is a DAG." << std::endl;
        return true;
    } else { 
        std::cout << "Given graph is not a DAG." << std::endl;
        return false;
    }

}

int main(){ 
    directedGraph DCG;
    DCG.createNode(1);
    DCG.createNode(2);
    DCG.createNode(3);
    DCG.createNode(4);

    DCG.connect(1,2);
    DCG.connect(2,3);
    DCG.connect(3,4);
    DCG.connect(4,1);

    DCG.print();

    checkDAG(DCG);

}