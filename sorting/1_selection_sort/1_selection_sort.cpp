#include<bits/stdc++.h>

using namespace std;

void selection_sort(vector<int>& arr) {
    int min_;
    for (int i=0; i<arr.size()-1; i++){
        min_ = i;
        for (int j=i+1; j<arr.size(); j++) {
            if (arr[j] < arr[min_]) {
                min_ = j;
            }
        }
        if (min_ != i) {
            swap(arr[i], arr[min_]);
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 6, 3, 7, 2};

    selection_sort(arr);

    for (int x: arr) {
        cout << x << " ";
    }
    cout << "\n";
}
