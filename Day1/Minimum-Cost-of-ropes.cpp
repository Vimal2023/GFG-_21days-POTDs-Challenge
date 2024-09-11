#include <iostream>
#include <vector>
#include <queue>
#include <functional> 
using namespace std;

class Solution {
  public:
    long long minCost(vector<long long>& arr) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr.begin(), arr.end());
        
        long long totalCost = 0;
        while (pq.size() > 1) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            long long cost = first + second;
            totalCost += cost;
            pq.push(cost);
        }
        
        return totalCost;
    }
};

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}
