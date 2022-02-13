#include <iostream>

using namespace std;

int sorted[8];

void merge(int a[], int m, int middle, int n){
    int i = m;
    int j = middle+1;
    int k = m;
    
    while(i<=middle && j<=n){
        if(a[i] < a[j]){
            sorted[k] = a[i];
            i++;
        }
        else{
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    
    if(i > middle){
        for(int t = j; t<=n; t++){
            sorted[k] = a[t];
            k++;
        }
    }
    else{
        for(int t = i; t<=middle; t++){
            sorted[k] = a[t];
            k++;
        }
    }
    for(int t = m; t<=n; t++){
        a[t] = sorted[t];
    }
}

void mergesort(int a[], int m, int n){
    if(m >= n) return;
    
    int mid = (m+n)/2;
    
    mergesort(a, m, mid);
    mergesort(a, mid+1, n);
    merge(a, m, mid, n);
}

int main(){
    
    int arr[8] = {1,4,2,5,2,4,8,0};
    
    mergesort(arr, 0, 7);
    
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
