#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isRight(string str)
{    
    stack<int> st;    
    for (char c : str)
    {
        if (c == '(') st.push(c);
        else
        {
            if (!st.empty() && st.top() == '(') st.pop();
            else return false;
        }
    }
    
    return st.empty();
}

string modifyString(string str)
{
    string modified = "";
    str = str.substr(1, str.length() - 2);
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '(') modified += ")";
        else modified += "(";
    }
    
    return modified;
}

string answer = "";
string solution(string p) {
    if (p.empty()) return "";
    
    int openCount = 0, closeCount = 0;
    int i = 0;
    do
    {
        if (p[i] == '(') ++openCount;
        else ++closeCount;
        ++i;
    }
    while (openCount != closeCount);
    
    string u = p.substr(0, i), v = p.substr(i);
    if (isRight(u)) return u + solution(v);
    else
    {
        string str = "(" + solution(v) + ")";
        return str + modifyString(u);
    }
    
    return answer;
}