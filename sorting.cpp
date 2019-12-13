#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <ctime>
#include "sorting.h"

using namespace std;

string test(int s, int n){
    string arrSorted[s];
    string arrReverse[s];
    string arrRandom[s];

    ifstream file ( "dati.csv" );
    clock_t t;

    vector<clock_t> dur1;
    vector<clock_t> dur2;
    vector<clock_t> dur3;

    for(int i = 0; i<n; i++){
        setArr(file, arrSorted, arrReverse, arrRandom, s);

        t = clock();
        heapSort(arrSorted, s);
        dur1.push_back(clock() - t);

        t = clock();
        heapSort(arrReverse, s);
        dur2.push_back(clock() - t);

        //printArr(arrRandom, s);
        t = clock();
        heapSort(arrRandom, s);
        dur3.push_back(clock() - t);
        //printArr(arrRandom, s);
    }

    return to_string(s)+ "," + to_string(getAvg(dur1)) + "," + to_string(getAvg(dur2)) + "," + to_string(getAvg(dur3));
}

int main(){
    ofstream filex;

    filex.open("rezultats.csv");
    filex << "izmers,sakartots,preteji,nesakartots" << endl;

    for(int i = 1; i < 11; i++){
        cout << "Testee " << i*1000 << "lielus masivus..." << endl;
        filex << test(i*1000, 5) << endl;
    }
}
