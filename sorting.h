#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED
#include <fstream>
#include <iostream>
using namespace std;

template <class T>
void swaps(T &x,T &y){
     T temp = x;
     x = y;
     y = temp;
}

template <class T>
int partition (T arr[], int low, int high)
{
    T pivot = arr[high];    // pivot
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swaps(arr[i], arr[j]);
        }
    }
    swaps(arr[i+1], arr[high]);
    return i + 1;
}
template <class T>
void quickSort(T arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

template <class T>
void printArr(T arr[], int s){
    for(int i = 0; i < s; i++)cout << i << ". " << arr[i] << endl;
}

template<class T>
void revArr(T arr[], int s){
    int f = 0;
    while (f < s){
        T temp = arr[f];
        arr[f] = arr[s-1];
        arr[s-1] = temp;
        f++;
        s--;
    }
}


void read(ifstream &file){
    string line;
    while(file.good()){
        getline(file, line);
        cout << line << endl;
    }
}

template<class T>
void setArr(ifstream &file, T arr1[], T arr2[], T arr3[], int s){
    string line;
    int lineCount = 0;
    int len;
    int comma = 0;
    string element;

    while(file.good()){
        if(lineCount == 0){
            lineCount++;
            continue;
        }

        lineCount++;
        //cout << lineCount << endl;
        getline(file, line);

        comma = 0;
        len = line.length();
        for(int i = 0; i<len; i++){
            if(line[i] == ','){
                element = "";
                comma++;
                continue;
            }
            element += line[i];

            if(comma == 1)arr1[lineCount] = element;
            if(comma == 2)arr2[lineCount] = element;
            if(i == len - 1)arr3[lineCount] = element;
        }
        if(lineCount == s-1)break;
    }

}

//void resetArr(string arr[], string arr2[], string arr3[]){

 //}



#endif // QUICKSORT_H_INCLUDED
