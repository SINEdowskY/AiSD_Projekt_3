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
    int edgeAmount, verticeAmount;

    static bool matrixValidation(vector<vector<int>> matrix){
        bool result = false;
        int minus, plus;

        for(int i = 0; i < matrix[0].size();i++){
            plus = 0;
            minus = 0;
            for(auto & el : matrix){
                if(el[i] == 1){
                    plus++;
                }
                else if(el[i] == -1){
                    minus++;
                }
            }
            if((plus == 1 || minus == 1) && plus >= minus){
                result = true;
            }
            else {
                result = false;
                break;
            }
        }
        return result;
    }

public:
    Graph(vector<vector<int>> matrix){

        if(matrixValidation(matrix)){
            this->matrix = matrix;
            this->edgeAmount = matrix.size();
            this->verticeAmount = matrix[0].size();
        }
        else{
            cout << "Macierz nie spelnia wymagan do bycia macierza incyndecji"<<endl;
        }

    }

    vector<int,vector<int>> getVertexNeighbors(){
    }
    //vertice [0,0,0,...,0] done
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
    //amount of -1 in vertice done
    vector<vector<int>> getVerticesIndegrees(){
        vector<vector<int>> result;
        int count = 0;
        int index = 1;

        for(vector<int> el: this->matrix){
            for(int cell: el){
                if(cell == -1){
                    count++;
                }
            }
            result.push_back({index, count});
            index++;
            count = 0;
        }
        return result;
    }
    // amount of 1 in vertice done
    vector<vector<int>> getVerticesOutdegrees(){
        vector<vector<int>> result;
        int count = 0;
        int index = 1;

        for(const vector<int>& el: this->matrix){
            for(int cell: el){
                if(cell == 1){
                    count++;
                }
            }
            result.push_back({index, count});
            index++;
            count = 0;
        }
        return result;
    }

    vector<string> getBidirectionalEdges(){

    }
    // edge where 1 distinct
    vector<int> getLoops(){

    }
};


#endif //GRAFALGORYTMYPROJEKT3_GRAPH_H
