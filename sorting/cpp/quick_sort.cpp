#include<bits/stdc++.h>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i<j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
    
        while (arr[j] > pivot && j > low) {
            j--;
        }
    
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}


/*
 * Quick Sort Logic:
 * Pick a pivot index (low(0-th) index in this case)
 * Move the pivot to its correct place in the sorted array
 * Move the elements smaller than the pivot to the left of it
 * Move the elements greater than the pivot to the right of it
*/
void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIdx = partition(arr, low, high);
        quick_sort(arr, low, pivotIdx - 1);
        quick_sort(arr, pivotIdx + 1, high);
    }
}

int main() {
    vector<int> v = {4,2,1,6,7};
    quick_sort(v, 0, v.size()-1);

    for (int i: v) {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}
