#include <iostream>
#include <vector>
#include "Graph.h"
#include <chrono>
#include <bits/stdc++.h>

long double timer(const vector<vector<int>> arr,const function<vector<int>(vector<vector<int>>)> algorithm,int count){
    long double sum = 0; //zmienna dla sumy czasow wykonania algorytmu

    for( int i = 0; i <= count; i++ ){
        auto startA = chrono::steady_clock::now(); //start zegara
        algorithm(arr); // wybrany wczesniej algorytm
        auto stopA = chrono::steady_clock::now(); //stop zegara
        auto durationA = stopA - startA; //roznica czasow
        sum += chrono::duration<long double, nano> (durationA).count(); //zmiennoprzecinkowe zapisanie do zmiennej
    }
    return sum/count; //zwracanie sredniej czasow
}

vector<vector<int>> user_matrix(int rows, int columns){
    vector<vector<int>> result;
    int a;

    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){
            cin >> a;
            result[i][j] = a;
        }
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

    Graph graph(A);

    for(vector<int> el: A){
        cout << "[";
        for(int cell: el){
            cout << setw(2) << cell << " ";
        }
        cout << "]"<<endl;
    }
    cout << endl;

    cout << "Podpunkt 1: Wszyscy sasiedzi dla kazdego wierzcholka"<<endl;

    auto start = chrono::steady_clock::now();
    vector<Graph::int_vector> ad1 = graph.getVerticeNeighbors();
    auto stop = chrono::steady_clock::now();
    auto time = chrono::duration<long double, milli> (stop - start).count();

    cout << endl;
    for(auto el: ad1){
        cout << el.num<<": ";
        for(auto cell: el.arr){
            cout << cell << ", ";
        }
        cout << endl;
    }

    cout << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    cout << endl;

    cout << "Podpunkt 2: Wszystkie wierzcholki, ktore sa sasiadami kazdego wierzcholka"<<endl;
    start = chrono::steady_clock::now();
    vector<int> ad2 = graph.getNeighborsOfAll();
    stop = chrono::steady_clock::now();
    time = chrono::duration<long double, milli> (stop - start).count();

    cout << endl;
    if(!ad2.empty()){
        for(int el: ad2){
            cout << el << ",";
        }
    }
    else{
        cout << "Brak sasiadow kazdego wierzcholka"<<endl;
    }
    cout << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    cout << endl;

    cout << "Podpunkt 3: Stopnie wychodzace wszystkich wierzczolkow"<<endl;
    start = chrono::steady_clock::now();
    vector<vector<int>> ad3 = graph.getVerticesOutdegrees();
    stop = chrono::steady_clock::now();
    time = chrono::duration<long double, milli> (stop - start).count();

    cout << endl;
    for(vector<int> el: ad3){
        cout << el[0] << ": " << el[1] <<" Stopien"<<endl;
    }
    cout << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    cout << endl;

    cout << "Podpunkt 4: Stopnie wchodzace wszystkich wierzczolkow"<<endl;
    start = chrono::steady_clock::now();
    vector<vector<int>> ad4 = graph.getVerticesIndegrees();
    stop = chrono::steady_clock::now();
    time = chrono::duration<long double, milli> (stop - start).count();

    cout << endl;
    for(vector<int> el: ad4){
        cout << el[0] << ": " << el[1] <<" Stopien"<<endl;
    }
    cout << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    cout << endl;

    cout << "Podpunkt 5: Wierzcholki izolowane"<<endl;
    start = chrono::steady_clock::now();
    vector<int> ad5 = graph.getIsolatedVertices();
    stop = chrono::steady_clock::now();
    time = chrono::duration<long double, milli> (stop - start).count();


    cout << endl;
    cout << "Wierzcholki: ";
    if(!ad5.empty()){
        for(int el: ad5){
            cout << el <<',';
        }
    }
    else{
        cout << "Brak wierzcholkow izolowanych" << endl;
    }
    cout << endl;
    cout << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    cout << endl;

    cout << "Podpunkt 6: Petle"<<endl;
    start = chrono::steady_clock::now();
    vector<int> ad6 = graph.getLoops();
    stop = chrono::steady_clock::now();
    time = chrono::duration<long double, milli> (stop - start).count();


    cout << endl;
    cout << "Krawedzie: ";
    if(!ad6.empty()){
        for(int el: ad6){
            cout << el <<',';
        }
    }
    else{
        cout << "Brak petli" << endl;
    }
    cout << endl;
    cout << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    cout << endl;

    cout << "Podpunkt 7: Krawedzie dwukierunkowe"<<endl;
    start = chrono::steady_clock::now();
    vector<vector<int>> ad7 = graph.getBidirectionalEdges();
    stop = chrono::steady_clock::now();
    time = chrono::duration<long double, milli> (stop - start).count();

    cout << endl;

    if(!ad7.empty()){
        for(vector<int> el: ad7){
            cout << el[0] << " : " << el[1]<< endl;
        }
    }
    else{
        cout << "Brak krawedzi dwukierunkowych" << endl;
    }
    cout << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    cout << endl;

    return 0;
}
