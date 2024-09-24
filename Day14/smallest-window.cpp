#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string smallestWindow(string s, string p) {
        if (p.length() > s.length()) return "-1";
        
        vector<int> patFreq(128, 0), windowFreq(128, 0);
        for (char c : p) patFreq[c]++;
        
        int start = 0, minLen = INT_MAX, matchedCount = 0, startIndex = -1;
        
        for (int end = 0; end < s.length(); end++) {
            char currChar = s[end];
            windowFreq[currChar]++;
            
            if (patFreq[currChar] != 0 && windowFreq[currChar] <= patFreq[currChar]) matchedCount++;
            
            while (matchedCount == p.length()) {
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    startIndex = start;
                }
                
                char leftChar = s[start];
                windowFreq[leftChar]--;
                if (patFreq[leftChar] != 0 && windowFreq[leftChar] < patFreq[leftChar]) matchedCount--;
                start++;
            }
        }
        
        if (startIndex == -1) return "-1";
        return s.substr(startIndex, minLen);
    }
};

int main() {
    Solution solution;
    string s = "timetopractice";
    string p = "toc";
    cout << solution.smallestWindow(s, p) << endl;
    return 0;
}
