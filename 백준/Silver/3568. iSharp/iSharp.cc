#include <bits/stdc++.h>
using namespace std;

int main()
{
    string statement;
    getline(cin, statement);
    
    stringstream ss(statement);
    string buffer;
    vector<string> v;
    
    while (ss >> buffer) v.push_back(buffer);
    string type = v[0];
    
    for (auto it = v.begin() + 1; it != v.end(); ++it)
    {
        string result = type;
        for (auto iter = (*it).rbegin() + 1; isalpha(*iter) == 0; ++iter) 
        {
        	if (*iter == ']') result += '[';
        	else if (*iter == '[') result += ']';
        	else result += *iter;
        }
        result += " ";
        for (char& c : (*it))
        {
        	if (isalpha(c) > 0) result += c;
        }
        result += ";";
        
        cout << result << endl;
    }
}