#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <chrono>
#include <ctime>
#include "sorting.h"
typedef std::chrono::high_resolution_clock Clock;

using namespace std;

string test(int s, ifstream &file){
    vector<int> dur1;
    vector<int> dur2;
    vector<int> dur3;

    string arrRandom[s];
    string arrSorted[s];
    string arrReversed[s];

    clock_t t = 0;
    int avg1 = 0, avg2 = 0, avg3 = 0;
    for(int i = 0; i < 2; i++){         // algoritmu var testet vairakas reizes lai iegutu precizakus rezultatus
        setArr(file, arrSorted, arrReversed, arrRandom, s); // reseto masivus

        t = clock();
        heapSort(arrSorted, s);
        dur1.push_back(clock() - t);

        t = clock();
        heapSort(arrReversed, s);
        dur2.push_back(clock() - t);

        t = clock();
        heapSort(arrRandom, s);
        //printArr(arrRandom, s);
        dur3.push_back(clock() - t);
    }
    avg1 = getAvg(dur1);
    avg2 = getAvg(dur2);
    avg3 = getAvg(dur3);
    //cout << dur1.size() << endl;

    return to_string(s) + "," + to_string(avg1) + "," + to_string(avg2) + "," + to_string(avg3);

}

int main(){
    auto t1 = Clock::now();
    auto t2 = Clock::now();
    ifstream file ( "dati.csv" );
    ofstream filex;
    filex.open("rezultats.csv");
    filex << "izmers,sakartots,preteji,nesakartots";
        std::cout << "Delta t2-t1: "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
              << " nanoseconds" << std::endl;
    //cout << test(4000, file) << endl;
}
