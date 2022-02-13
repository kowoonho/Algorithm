#include <iostream>

using namespace std;

int partition(int arr[], int start, int end){
    int pivot_index = (start + end)/2;
    int pivot_value = arr[pivot_index];
    
    int current = start;
    swap(arr[end], arr[pivot_index]);
    
    for(int i = start; i<end; i++){
        if(arr[i] <= pivot_value){
            swap(arr[i], arr[current]);
            current++;
        }
    }
    
    swap(arr[current], arr[end]);
    return current;
}

void quicksort(int arr[], int start, int end){
    if(start >= end) return;
    
    int pivotindex = partition(arr, start, end);
    quicksort(arr, start, pivotindex-1);
    quicksort(arr, pivotindex+1, end);
}

int main(){
    
    int arr[8] = {9,8,7,6,5,4,3,2};
    
    quicksort(arr, 0, 7);
    
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
