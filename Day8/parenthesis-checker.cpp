#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
    public:
    bool ispar(string x)
    {
        stack<char> s;
        for(char c : x) {
            if(c == '(' || c == '{' || c == '[') {
                s.push(c);
            }
            else {
                if(s.empty()) return false;
                char top = s.top();
                if((c == ')' && top == '(') || 
                   (c == '}' && top == '{') || 
                   (c == ']' && top == '[')) {
                    s.pop();
                }
                else {
                    return false;
                }
            }
        }
        return s.empty();
    }
};

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
