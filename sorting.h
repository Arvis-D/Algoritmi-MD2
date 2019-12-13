#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
void swaps(T &x,T &y){
     T temp = x;
     x = y;
     y = temp;
}

template <class T>
void heapify(T arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template <class T>
void heapSort(T arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swaps(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

template <class T>
void printArr(T arr[], int s){
    for(int i = 0; i < s; i++)cout << i << ". " << arr[i] << endl;
}
template <class T>
void printVec(vector<T> *arr){
    for(int i = 0; i < arr.size(); i++)cout << i << ". " << arr[i] << endl;
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
        getline(file, line);
        comma = 0;
        len = line.length();
        for(int i = 0; i<len; i++){
            if(line[i] == ','){
                comma++;

                if(comma == 1)arr1[lineCount] = element;
                if(comma == 2)arr2[lineCount] = element;
                element = "";

                continue;
            }
            element += line[i];
            if(i == len-1){
                arr3[lineCount] = element;
                element = "";
            }
        }
        if(lineCount == s-1)break;
    }

}

template<class T>
T getAvg(vector<T> nums){
    if(nums.size() == 0)return 0;

    int n = 0;
    T x = 0;
    for(int i = 0; i<nums.size(); i++){
        n++;
        x += nums[i];
    }

    return x/n;
}
//void resetArr(string arr[], string arr2[], string arr3[]){

 //}



#endif // QUICKSORT_H_INCLUDED
