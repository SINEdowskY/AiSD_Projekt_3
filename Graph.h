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
    vector<vector<int>> matrix; //zmienna zapisujaca macierz
    vector<vector<int>> edgeMap; //zmienna zapisujaca macierz krawedzi {source, destination}
    vector<int> loops; //zmienna zapisujaca tablice petli
    vector<int> isolated; //zmienna zapisujaca tablice wierzcholkow izolowanych
    int edgeAmount, verticeAmount; //zmienne zapisujace (kolejno) ilosc krawedzi i ilosc wierzcholkow

    //funkcja sprawdzajaca czy podana macierz jest macierza incydencji
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
            if((plus == 1 || minus == 1) && plus >= minus && plus == 1){
                result = true;
            }
            else {
                result = false;
                break;
            }
        }
        return result;
    }
    //funckja generujaca macierz krawedzi
    void edgeMapping(){
        int plusPosition, minusPosition;

        for(int i = 0; i < this->edgeAmount; i++){
            plusPosition = -1;
            minusPosition = -1;

            for(int j = 0; j < this->verticeAmount; j++){
                if(this->matrix[j][i] == 1){
                    plusPosition = j;
                }
                else if(this->matrix[j][i] == -1){
                    minusPosition = j;
                }

            }
            this->edgeMap.push_back({plusPosition,minusPosition});

        }
    }

public:

    //konstruktor
    Graph(vector<vector<int>> matrix){

        if(matrixValidation(matrix)){
            this->matrix = matrix;
            this->edgeAmount = matrix[0].size();
            this->verticeAmount = matrix.size();
            this->loops = this->getLoops();
            this->isolated = this->getIsolatedVertices();
            edgeMapping();
        }
        else{
            cout << "Macierz nie spelnia wymagan do bycia macierza incyndecji"<<endl;
        }

    }

    // struktura roznowartosciowa dla vectora
    struct int_vector{
        int num;
        vector<int> arr;
    };

    // Podpunkt 1)
    vector<int_vector> getVerticeNeighbors(){
        vector<int_vector> result;
        vector<int> neighbours;
            for(int i = 0; i < this->verticeAmount; i++){
                for(int j = 0; j < this->edgeAmount; j++){
                    if(this->matrix[i][j] == 1){
                        for(int k = 0; k < this->verticeAmount; k++){
                            if(matrix[k][j] == -1){
                                neighbours.push_back(k);
                                break;
                            }
                        }
                    }
                }
                result.push_back({i,neighbours});
                neighbours.clear();
            }


        return result;
    }

    // Podpunkt 2)
    vector<int> getNeighborsOfAll(){
        vector<int> result;
        int sum;

        if(isolated.empty()){
            for(int i = 0; i < verticeAmount; i++){
                sum = 0;
                for(int j = 0; j < edgeAmount; j++){
                    for(int el : this->loops){
                        if(j != el){
                            if(this->matrix[i][j] == 1){
                                sum++;
                            }
                        }
                    }
                }
                if(sum == this->verticeAmount){
                    result.push_back(i);
                }
            }
        }

        return result;
    }

    // Podpunkt 3)
    vector<vector<int>> getVerticesOutdegrees(){
        vector<vector<int>> result;
        int count = 0;
        int index = 1;

        for(vector<int> el: this->matrix){
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

    // Podpunkt 4)
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

    // Podpunkt 5)
    vector<int> getIsolatedVertices(){
        vector<int> result;
        int index = 0;
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
                result.push_back(index);
            }
            index++;
        }

        return result;
    }

    // Podpunkt 6)
    vector<int> getLoops(){
        vector<int> result;
        int zero, plus;

        for(int i = 0; i < matrix[0].size();i++){
            zero = 0;
            plus = 0;
            for(auto & el : matrix){
                if(el[i] == 0){
                    zero++;
                }
                else if(el[i] == 1){
                    plus++;
                }
            }
            if(plus+zero==this->verticeAmount){
                result.push_back(i);
            }
        }

        return result;
    }

    // Podpunkt 7)
    vector<vector<int>> getBidirectionalEdges(){
        vector<vector<int>> result;
        int source, destiantion;
        bool check = false;

        for(int i = 0; i <this->edgeMap.size(); i++){
            source = this->edgeMap[i][0];
            destiantion = this->edgeMap[i][1];
            for(int j = 0; j < this->edgeMap.size(); j++){
                if(source == this->edgeMap[j][1] && destiantion == this->edgeMap[j][0]){
                    if(!result.empty()){
                        for(auto el: result){
                            if(el[0] != destiantion && el[1] != source){
                                check = true;
                            }
                        }
                        if(!check){
                            result.push_back({i,j});
                        }
                    }
                    else{
                        result.push_back({i,j});
                    }
                }
            }
        }

        return result;
    }

};


#endif //GRAFALGORYTMYPROJEKT3_GRAPH_H
