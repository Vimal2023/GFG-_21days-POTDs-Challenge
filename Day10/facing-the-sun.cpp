#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
  public:
    int countBuildings(vector<int> &height) {
        int count = 0;
        int max_height = 0;
        
        for (int h : height) {
            if (h > max_height) {
                count++;
                max_height = h;
            }
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> height;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            height.push_back(number);
        }
        Solution ob;
        int ans = ob.countBuildings(height);
        cout << ans << endl;
    }
    return 0;
}
