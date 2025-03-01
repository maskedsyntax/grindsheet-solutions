#include<bits/stdc++.h>

using namespace std;

void merge(vector<int>& arr, int low,int mid , int high) {
    vector<int> temp;
    int l = low;
    int r = mid+1;

    while (l <= mid && r <= high) {
        if (arr[l] <= arr[r]) {
            temp.emplace_back(arr[l]);
            l++;
        }
        else {
            temp.emplace_back(arr[r]);
            r++;
        }
    }

    // if left is stell left
    while(l <= mid) {
        temp.emplace_back(arr[l]);
        l++;
    }
    
    // if right is still left
    while(r <= high) {
        temp.emplace_back(arr[r]);
        r++;
    }
    
    for (int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
    }

}


/*
 * Merge Sort Logic:
 * if low <= high: return
 * Find the mid-point using low and high
 * merge each sorted half of the array using merge()
*/
void merge_sort(vector<int>& arr, int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);

    merge(arr, low, mid, high);
}

int main() {
    vector<int> v = {4,2,1,6,7};
    merge_sort(v, 0, v.size()-1);

    for (int i: v) {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}
