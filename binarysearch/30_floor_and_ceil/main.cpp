#include<iostream>
#include<vector>

using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int l = 0, r = n-1;
	pair<int, int> ans{-1, -1};

	while (l <= r) {
		long long mid = l + (r - l) /2;
		

		if (a[mid] == x) return make_pair(a[mid], a[mid]);

		else if (a[mid] > x) {
			ans.second = a[mid];
			r = mid - 1;
		}

		else {
			ans.first = a[mid];
			l = mid + 1;
		}

	}

	return ans;

}