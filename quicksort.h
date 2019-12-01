#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

using namespace std;

template <class T>
void swaps(T &x,T &y){
     T temp;
     temp = x;
     x = y;
     y = temp;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
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
void quickSort(int arr[], int low, int high)
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
T revArr(T arr[], int s){
    T temp[s];
    for(int i = s; i>=0; i--)temp[s-i] = arr[i];
    return temp;
}


#endif // QUICKSORT_H_INCLUDED
