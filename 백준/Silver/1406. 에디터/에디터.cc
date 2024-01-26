#include <bits/stdc++.h>
using namespace std;

list<char> li;
list<char>::iterator it;

void Editor(char order)
{
    if (order == 'L' && it != li.begin())
        --it;
    else if (order == 'D' && it != li.end())
        ++it;
    else if (order == 'B' && it != li.begin())
        it = li.erase(--it);
    else if (order == 'P')
    {
        char ch;
        cin >> ch;
        li.insert(it, ch);
    }
}

int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i)
        li.push_back(str[i]);
    
    it = li.end();
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        char ch;
        cin >> ch;
        Editor(ch);
    }
    
    for (auto it = li.begin(); it != li.end(); ++it)
        cout << *it;
}