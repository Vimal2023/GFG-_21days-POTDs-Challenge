#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
  public:
    int totalCount(int k, vector<int>& arr) {
        int totalParts = 0;
        for (int num : arr) {
            totalParts += num / k;
            if (num % k != 0) {
                totalParts++;
            }
        }
        return totalParts;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        int res = obj.totalCount(k, arr);
        cout << res << endl;
    }
    return 0;
}
