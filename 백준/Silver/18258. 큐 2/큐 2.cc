#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    queue<int> q;
    int num, ans;
    string str;
    getline(cin, str);
    num = stoi(str);
    
    for (int i = 0; i < num; ++i)
    {
        getline(cin, str);
               
        if (str == "pop")
        {
            if (q.empty()) cout << -1 << '\n';
            else 
            {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (str == "size")
        {
            cout << q.size() << '\n';
        }
        else if (str == "empty")
        {
            ans = q.empty() ? 1 : 0;
            cout << ans << '\n';
        }
        else if (str == "front")
        {
            ans = q.empty() ? -1 : q.front();
            cout << ans << '\n';
        }
        else if (str == "back")
        {
            ans = q.empty() ? -1 : q.back();
            cout << ans << '\n';
        }
        else if (str.find("push") != string::npos)
        {
            q.push(stoi(str.substr(5)));
        }
    }
    
    return 0;
}