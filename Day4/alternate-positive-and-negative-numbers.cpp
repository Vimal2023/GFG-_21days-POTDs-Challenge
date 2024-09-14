#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Solution {
  public:
    void rearrange(vector<int>& arr) {
        vector<int> pos;
        vector<int> neg;
        
        for (int num : arr) {
            if (num >= 0) pos.push_back(num);
            else neg.push_back(num);
        }
        
        int i = 0, p = 0, n = 0;
        while (p < pos.size() && n < neg.size()) {
            arr[i++] = pos[p++];
            arr[i++] = neg[n++];
        }
        
        while (p < pos.size()) {
            arr[i++] = pos[p++];
        }
        
        while (n < neg.size()) {
            arr[i++] = neg[n++];
        }
    }
};

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        cout << "Enter array elements: ";
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        
        Solution ob;
        ob.rearrange(arr);
        
        cout << "Rearranged array: ";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
