#include <iostream>
using namespace std;
#include <vector>

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;
    for(int i = start+1; i<=end; i++) {
        if(arr[i] < pivot) {
            count++;
        }
    }
    int pivotIndex = start+count;
    swap(arr[start], arr[pivotIndex]);
    int left = start;
    int right = end;
    while(left<pivotIndex && right > pivotIndex) {
        while(arr[left] <= pivot) {
            left++;
        }
        while(arr[right] > pivot) {
            right--;
        }
        if(left < pivotIndex && right>pivotIndex) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int start, int end) {
    if(start > end) {
        return;
    }
    int p = partition(arr, start, end);
    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
}

int main() {
  int arr[8] = {1, 7, 8, 5, 3, 6, 4, 2};
    quickSort(arr, 0, 7 );
  for(auto d: arr) {
      cout<<d<<", ";
  }
}


