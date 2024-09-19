#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>


using namespace std;

class Solution {
  public:
    string reverseWords(string str) {
        vector<string> words;
        stringstream ss(str);
        string word;
        
        while (getline(ss, word, '.')) {
            words.push_back(word);
        }
        
        reverse(words.begin(), words.end());
        
        string result = words[0];
        for (int i = 1; i < words.size(); i++) {
            result += "." + words[i];
        }
        
        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}