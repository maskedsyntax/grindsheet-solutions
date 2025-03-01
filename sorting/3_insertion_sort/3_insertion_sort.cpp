#include<bits/stdc++.h>

using namespace std;

void insertion_sort(vector<int>& arr) {
    for (int i=1; i<arr.size(); i++){
        int x = i-1;
        int key = arr[i];
        while(x>=0 && arr[x] > key) {
            arr[x+1] = arr[x];
            x--;
        }
        arr[x+1] = key;
        cout << x << endl;
    }
}

int main() {
    vector<int> arr = {5, 2, 6, 3, 7, 2};

    insertion_sort(arr);

    for (int x: arr) {
        cout << x << " ";
    }
    cout << "\n";
}
