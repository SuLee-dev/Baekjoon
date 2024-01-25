#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> A, s, ans;

void Solve()
{
    while (!A.empty())
    {
        if (s.empty()) ans.push(-1);
        else if (s.top() <= A.top())
        {
            while (!s.empty() && s.top() <= A.top()) s.pop();
            if (s.empty()) ans.push(-1);
            else ans.push(s.top());
        }
        else if (s.top() > A.top()) ans.push(s.top());
    
        s.push(A.top());
        A.pop();
    }
}


int main()
{
    cin >> N;
    int x;
    for (int i = 0; i < N; ++i)
    {
        cin >> x;
        A.push(x);
    }
    
    Solve();
    
    while (!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }
}