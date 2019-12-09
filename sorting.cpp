#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <ctime>
#include "sorting.h"

using namespace std;

string test(int s, string arr1[], string arr2[], string arr3[], ifstream &file){
    vector<int> dur1;
    vector<int> dur2;
    vector<int> dur3;
    clock_t t1;
    clock_t t2;
    int avg1 = 0, avg2 = 0, avg3 = 0;
    for(int i = 0; i < 2; i++){
        setArr(file, arr1, arr2, arr3, s);

        t1 = clock();
        quickSort(arr1, 0, s-1);
        cout << "asd";
        t2 = clock();
        dur1.push_back(t2-t1);
        t1 = clock();
        quickSort(arr2, 0, s-1);
        t2 = clock();
        dur2.push_back(t2-t1);
        t1 = clock();
        quickSort(arr3, 0, s-1);
        t2 = clock();
        dur3.push_back(t2-t1);
    }
    avg1 = getAvg(dur1);
    avg2 = getAvg(dur2);
    avg3 = getAvg(dur3);

    return to_string(avg1) + "," + to_string(avg2) + "," + to_string(avg2);
}

int main(){
    int arrSize = 10000;
    string arrRandom[arrSize];
    string arrSorted[arrSize];
    string arrReversed[arrSize];
    ifstream file ( "dati.csv" );

    cout << test(arrSize, arrSorted, arrReversed, arrRandom, file);
}
