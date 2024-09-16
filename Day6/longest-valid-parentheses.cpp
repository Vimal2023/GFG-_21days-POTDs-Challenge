#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int maxLength(string& str) {
        stack<int> stk;
        stk.push(-1);
        int maxLength = 0;

        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (!stk.empty()) {
                    maxLength = max(maxLength, i - stk.top());
                } else {
                    stk.push(i);
                }
            }
        }

        return maxLength;
    }
};

int main() {
    Solution sol;
    string s1 = "((()";
    cout << "Longest valid parentheses length for \"" << s1 << "\": " << sol.maxLength(s1) << endl;
    
    string s2 = ")()())";
    cout << "Longest valid parentheses length for \"" << s2 << "\": " << sol.maxLength(s2) << endl;

    return 0;
}
