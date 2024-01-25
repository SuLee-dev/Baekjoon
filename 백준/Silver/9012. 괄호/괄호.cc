#include <bits/stdc++.h>
using namespace std;

int T;
char Parenthesis[50];

void IsVPS(string str)
{
    stack<char> s;
    
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(') s.push('(');
        else
        {
            if (!s.empty() && s.top() == '(') s.pop();
            else
            {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    
    if (s.empty()) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main()
{
    cin >> T;
    
    string str;
    for (int i = 0; i < T; ++i)
    {
        cin >> str;
        IsVPS(str);
    }
}