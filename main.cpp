#include <iostream>
#include <vector>
#include "Graph.h"
#include <chrono>
#include <bits/stdc++.h>
#include <fstream>
#include <string>

vector<vector<int>> user_matrix(int width, int height){
    vector<vector<int>> result;
    vector<int> temp;

    for(int i = 0; i < width; i++){
        for()
    }


    return result;
}

int main() {
    vector<vector<int>> A = {
            {1,1,0,0,0,1},
            {-1,0,-1,0,0,0},
            {0,-1,1,1,-1,0},
            {0,0,0,-1,1,0},
            {0,0,0,0,0,0}
    };

    vector<vector<int>> user = user_matrix(5,4);

    Graph graph(A);
    stringstream ss;
    ofstream file;


    for(vector<int> el: A){
        ss << "[";
        for(int cell: el){
            ss << setw(2) << cell << " ";
        }
        ss << "]"<<endl;
    }
    ss << endl;

    ss << "Podpunkt 1: Wszyscy sasiedzi dla kazdego wierzcholka"<<endl;

    auto start = chrono::steady_clock::now();
    vector<Graph::int_vector> ad1 = graph.getVerticeNeighbors();
    auto stop = chrono::steady_clock::now();
    auto time = chrono::duration<long double, milli> (stop - start).count();

    ss << endl;
    for(auto el: ad1){
        ss << el.num<<": ";
        for(auto cell: el.arr){
            ss << cell << ", ";
        }
        ss << endl;
    }

    ss << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    ss << endl;

    ss << "Podpunkt 2: Wszystkie wierzcholki, ktore sa sasiadami kazdego wierzcholka"<<endl;
    start = chrono::steady_clock::now();
    vector<int> ad2 = graph.getNeighborsOfAll();
    stop = chrono::steady_clock::now();
    time = chrono::duration<long double, milli> (stop - start).count();

    ss << endl;
    if(!ad2.empty()){
        for(int el: ad2){
            ss << el << ",";
        }
    }
    else{
        ss << "Brak sasiadow kazdego wierzcholka"<<endl;
    }
    ss << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    ss << endl;

    ss << "Podpunkt 3: Stopnie wychodzace wszystkich wierzczolkow"<<endl;
    start = chrono::steady_clock::now();
    vector<vector<int>> ad3 = graph.getVerticesOutdegrees();
    stop = chrono::steady_clock::now();
    time = chrono::duration<long double, milli> (stop - start).count();

    ss << endl;
    for(vector<int> el: ad3){
        ss << el[0] << ": " << el[1] <<" Stopien"<<endl;
    }
    ss << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    ss << endl;

    ss << "Podpunkt 4: Stopnie wchodzace wszystkich wierzczolkow"<<endl;
    start = chrono::steady_clock::now();
    vector<vector<int>> ad4 = graph.getVerticesIndegrees();
    stop = chrono::steady_clock::now();
    time = chrono::duration<long double, milli> (stop - start).count();

    ss << endl;
    for(vector<int> el: ad4){
        ss << el[0] << ": " << el[1] <<" Stopien"<<endl;
    }
    ss << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    ss << endl;

    ss << "Podpunkt 5: Wierzcholki izolowane"<<endl;
    start = chrono::steady_clock::now();
    vector<int> ad5 = graph.getIsolatedVertices();
    stop = chrono::steady_clock::now();
    time = chrono::duration<long double, milli> (stop - start).count();


    ss << endl;
    ss << "Wierzcholki: ";
    if(!ad5.empty()){
        for(int el: ad5){
            ss << el <<',';
        }
    }
    else{
        ss << "Brak wierzcholkow izolowanych" << endl;
    }
    ss << endl;
    ss << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    ss << endl;

    ss << "Podpunkt 6: Petle"<<endl;
    start = chrono::steady_clock::now();
    vector<int> ad6 = graph.getLoops();
    stop = chrono::steady_clock::now();
    time = chrono::duration<long double, milli> (stop - start).count();


    ss << endl;
    ss << "Krawedzie: ";
    if(!ad6.empty()){
        for(int el: ad6){
            ss << el <<',';
        }
    }
    else{
        ss << "Brak petli" << endl;
    }
    ss << endl;
    ss << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    ss << endl;

    ss << "Podpunkt 7: Krawedzie dwukierunkowe"<<endl;
    start = chrono::steady_clock::now();
    vector<vector<int>> ad7 = graph.getBidirectionalEdges();
    stop = chrono::steady_clock::now();
    time = chrono::duration<long double, milli> (stop - start).count();

    ss << endl;

    if(!ad7.empty()){
        for(vector<int> el: ad7){
            ss << el[0] << " : " << el[1]<< endl;
        }
    }
    else{
        ss << "Brak krawedzi dwukierunkowych" << endl;
    }
    ss << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    ss << endl;

    cout << ss.str();
    file.open("output.txt");
    file << ss.str();
    file.close();

    return 0;
}
