#include<bits/stdc++.h>
using namespace std;

int partition(int *arr,int s,int e){
    int pivot = arr[s];
    int count = 0;
    for(int i=s+1;i<=e;i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    int pivotIndex = s + count;
    swap(arr[s],arr[pivotIndex]);

    int i = s;
    int j = e;

    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>=pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivotIndex;

}

void QuickSort(int *arr,int s,int e){

    if(s>=e){
        return;
    }

    int p = partition(arr,s,e);

    QuickSort(arr,s,p-1);

    QuickSort(arr,p+1,e);

}

int main() {
    
    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int size = 15;

    QuickSort(arr,0,size-1);

    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }cout << endl;

}

// QuickSort is prefered over MergeSort(except in case of linked list)