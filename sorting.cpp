#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include "sorting.h"

using namespace std;



int main(){
    int arrSize = 10000;
    string arrRandom[arrSize];
    string arrSorted[arrSize];
    string arrReversed[arrSize];
    string x = "";
//    ofstream file;
    ifstream ifile;
/*
    for(int i = 0; i < arrSize; i++){
        for(int j = 0; j<20; j++)
            x += (rand()%25)+97;
        arrRandom[i] = x;
        arrSorted[i] = x;
        x = "";
    }

    quickSort(arrSorted, 0, arrSize-1);
    for(int i = 0; i<arrSize; i++)arrReversed[i] = arrSorted[i];
    revArr(arrReversed, arrSize);
*/
 //   file.open("dati.csv");
//    file << "arrSorted,arrReverse,arrRandom" << endl;
 //   for(int i = 0; i<arrSize; i++)
  //      file <<  arrSorted[i] << "," << arrReversed[i] << "," << arrRandom[i] << endl;


ifstream file ( "dati2.csv" );
    //read(file);
setArr(file, arrSorted, arrReversed, arrRandom, arrSize);
printArr(arrSorted, arrSize);
}
