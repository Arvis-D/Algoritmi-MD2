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
        t2 = clock();
        cout << (t2-t1) << endl;
        t1 = clock();
        quickSort(arr2, 0, s-1);
        t2 = clock();
        cout << (t2-t1) << endl;
        t1 = clock();
        printArr(arr3, s);
        quickSort(arr3, 0, s-1);
        t2 = clock();
        cout << (t2-t1) << endl;
    }
    avg1 = getAvg(dur1);
    avg2 = getAvg(dur2);
    avg3 = getAvg(dur3);

    return to_string(avg1) + "," + to_string(avg2) + "," + to_string(avg3);
}

int main(){
    int arrSize = 2000;
    string arrRandom[arrSize];
    string arrSorted[arrSize];
    string arrReversed[arrSize];
    ifstream file ( "dati.csv" );
    //setArr(file, arrSorted, arrReversed, arrRandom, arrSize);
    //printArr(arrRandom, arrSize);
    //printArr(arrSorted, arrSize);
    //vector<int> asd = {3,4,5};
    //cout << getAvg(asd);
    cout << test(arrSize, arrSorted, arrReversed, arrRandom, file);
}
