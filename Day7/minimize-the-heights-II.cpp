#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1)
            return 0;
        sort(arr.begin(), arr.end());
        int ans = arr[n - 1] - arr[0];
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;
        for (int i = 0; i < n - 1; i++) {
            int minHeight = min(smallest, arr[i + 1] - k);
            int maxHeight = max(largest, arr[i] + k);
            if (minHeight < 0)
                continue;
            ans = min(ans, maxHeight - minHeight);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 5, 8, 10};
    int k = 2;
    cout << sol.getMinDiff(arr, k) << endl;
    return 0;
}
