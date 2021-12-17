#include <iostream>
#include "Graph.h"
int main() {
    vector<vector<int>> A = {
            {0,0,0,0,0},
            {1,0,1,0,0},
            {-1,0,0,1,1},
            {0,0,0,0,0},
            {-1,-1,1,1,1}
    };

    Graph graph(A);

    vector<string> x = graph.getIsolatedVertices();
    for(auto el: x){
        cout << el << ", ";
    }

    return 0;
}
