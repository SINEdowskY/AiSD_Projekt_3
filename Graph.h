//
// Created by kub20 on 17/12/2021.
//

#ifndef GRAFALGORYTMYPROJEKT3_GRAPH_H
#define GRAFALGORYTMYPROJEKT3_GRAPH_H

#include <vector>
#include <string>

using namespace std;

class Graph {

private:
    vector<vector<int>> matrix;
    vector<vector<int>> matrix_transponse;
    vector<vector<int>> edge;

public:
    Graph(vector<vector<int>> matrix){
        this->matrix = matrix;
    }
    vector<string,vector<string>> getVertexNeighbors(){
    }
    //vertice [0,0,0,...,0]
    vector<string> getIsolatedVertices(){
        vector<string> result;
        int index = 1;
        bool test;

        for(vector<int> el: this->matrix){
            test = false;
            for(int i  = 0; i < el.size(); i++){
                if(el[i] != 0){
                    break;
                }
                if(i == el.size()-1){
                    test = true;
                }
            }
            if(test){
                result.push_back(string("Vertice")+ to_string(index));
            }
            index++;
        }

        if(result.empty()){
            result.push_back("None vertices are isolated");
        }
        return result;
    }
    // amount of (1 or -1) == edge amount
    vector<string> getNeighborsOfAll(){
        vector<string> result;
        int index = 1;
        string str;
        bool test;

        for(vector<int> el: this->matrix){
            test = false;
            for(int i = 0; i < el.size(); i++){
                if(el[i] == 0){
                   break;
                }
                if(i == el.size()-1){
                    test = true;
                }
            }
            if(test){
                result.push_back(string("Vertice ")+ to_string(index));
            }
            index++;
        }

        if(result.empty()){
            result.push_back("None of vertices are neighbor of all");
        }
        return result;
    }
    //amount of -1 in vertice
    vector<vector<string,int>> getVerticesIndegrees(){

    }
    // amount of 1 in vertice
    vector<vector<string,int>> getVerticesOutdegrees(){

    }

    vector<string> getBidirectionalEdges(){

    }
    // edge where 1 distinct
    vector<int> getLoops(){

    }
};


#endif //GRAFALGORYTMYPROJEKT3_GRAPH_H
