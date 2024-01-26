#include <bits/stdc++.h>
using namespace std;

list<char> li;
list<char>::iterator it;

void Print(list<char> li)
{
	for (auto it = li.begin(); it != li.end(); ++it)
        cout << *it;
        
    cout << '\n';
}

void Keylogger(string str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '<' && it != li.begin())
            --it;
        else if (str[i] == '>' && it != li.end())
            ++it;
        else if (str[i] == '-' && it != li.begin())
            it = li.erase(--it);
        else if (str[i] != '>' && str[i] != '<' && str[i] != '-')
			li.insert(it, str[i]);
    }
}

int main()
{
    int T;
    cin >> T;
    
    string str;
    for (int i = 0; i < T; ++i)
    {    
        cin >> str;
        li = list<char>();
        it = li.begin();
        Keylogger(str);
        
		Print(li);
    }
}