#include <iostream>
#include <vector>
#include "Graph.h"
#include <chrono>
#include <bits/stdc++.h>
#include <string>

void straight_info(vector<vector<int>> matrix){
    Graph graph(matrix);
    stringstream ss;
    ofstream file;


    for(vector<int> el: matrix){
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

    ss << endl << endl;
    ss << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    ss << endl;

    ss << "Podpunkt 2: Wszystkie wierzcholki, ktore sa sasiadami kazdego wierzcholka"<<endl;
    start = chrono::steady_clock::now();
    vector<int> ad2 = graph.getNeighborsOfAll();
    stop = chrono::steady_clock::now();
    time = chrono::duration<long double, milli> (stop - start).count();

    ss << endl;
    ss << "Wierzcholki: ";
    if(!ad2.empty()){
        for(int el: ad2){
            ss << el << ",";
        }
    }
    else{
        ss << "Brak sasiadow kazdego wierzcholka"<<endl;
    }
    ss << endl << endl;
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
    ss << endl << endl;
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
    ss << endl << endl;
    ss << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    ss << endl;

    ss << "Podpunkt 5: Wierzcholki izolowane"<<endl;
    start = chrono::steady_clock::now();
    vector<int> ad5 = graph.getIsolatedVertices();
    stop = chrono::steady_clock::now();
    time = chrono::duration<long double, milli> (stop - start).count();


    ss << endl;
    if(!ad5.empty()){
        ss << "Wierzcholki: ";
        for(int el: ad5){
            ss << el <<',';
        }
    }
    else{
        ss << "Brak wierzcholkow izolowanych" << endl;
    }
    ss << endl << endl;
    ss << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    ss << endl;

    ss << "Podpunkt 6: Petle"<<endl;
    start = chrono::steady_clock::now();
    vector<int> ad6 = graph.getLoops();
    stop = chrono::steady_clock::now();
    time = chrono::duration<long double, milli> (stop - start).count();


    ss << endl;
    if(!ad6.empty()){
        ss << "Krawedzie: ";
        for(int el: ad6){
            ss << el <<',';
        }
    }
    else{
        ss << "Brak petli" << endl;
    }
    ss << endl << endl;
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
    ss << endl << endl;
    ss << "Czas trwania algorytmu: "<<time<<" ms"<<endl;
    ss << endl;

    cout << ss.str();
    file.open("output.txt");
    file << ss.str();
    file.close();
}

int main() {
    vector<vector<int>> A = { // A: Zawiera: petle, wierzcholek izolowany i krawedzie dwukierunkowe
            {1,1,0,0,0,1},
            {-1,0,-1,0,0,0},
            {0,-1,1,1,-1,0},
            {0,0,0,-1,1,0},
            {0,0,0,0,0,0}
    };

    vector<vector<int>> B = { //B: Zawiera: sasiada kazdego wierzcholka
            {-1,-1,-1,-1},
            {1,0,0,0},
            {0,1,0,0},
            {0,0,1,0},
            {0,0,0,1}
    };
    bool check = true;
    int input;
    while(check){
        cout << "Wybierz macierz :"<<endl;
        cout << "1 :A: Zawiera: petle, wierzcholek izolowany i krawedzie dwukierunkowe"<<endl;
        cout << "2 :B: Zawiera: sasiada kazdego wierzcholka" << endl;
        cin >> input;
        if(input == 1){
            straight_info(A);
            check = false;
        }
        else if(input == 2){
            straight_info(B);
            check = false;
        }
        else{
            cout << "Zla liczba !"<<endl;
        }
    }

    return 0;
}
