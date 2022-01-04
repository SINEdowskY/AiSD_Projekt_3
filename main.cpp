#include <iostream>
#include "Graph.h"

int main() {
    vector<vector<int>> A = {
            {1,1,0,0,0,1},
            {-1,0,-1,0,0,0},
            {0,-1,1,1,-1,0},
            {0,0,0,-1,1,0},
    };

    Graph graph(A);

    vector<vector<int>> x = graph.getVerticesOutdegrees();
    for(auto el: x){
        cout << "Vertice " << el[0] << ", "<< el[1] <<endl;
    }

    return 0;
}
