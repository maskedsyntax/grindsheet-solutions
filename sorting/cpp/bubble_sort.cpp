#include<bits/stdc++.h>

using namespace std;

void bubble_sort(vector<int>& arr) {
    for (int i=0; i<arr.size()-1; i++){
        for (int j=i+1; j<arr.size(); j++) {
            if (arr[i] > arr[j]) swap(arr[i], arr[j]);
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 6, 3, 7, 2};

    bubble_sort(arr);

    for (int x: arr) {
        cout << x << " ";
    }
    cout << "\n";
}
