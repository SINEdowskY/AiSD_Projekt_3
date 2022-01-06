#include <iostream>
#include "Graph.h"

int main() {
    vector<vector<int>> A = {
            {1,1,0,0,0,1},
            {-1,0,-1,0,0,0},
            {0,-1,1,1,-1,0},
            {0,0,0,-1,1,0},
            {0,0,0,0,0,0}
    };

    Graph graph(A);


    vector<vector<int>> y = graph.getBidirectionalEdges();

    for(auto el: y){
        cout << el[0] << " : " << el[1]<< endl;
    }
/*
    vector<Graph::int_vector> x = graph.getVerticeNeighbors();
    for(auto el: x){
        cout << el.num<<": ";
        for(auto cell: el.arr){
            cout << cell << ", ";
        }
        cout <<endl;
    }
*/
    return 0;
}
