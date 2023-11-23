#include <bits/stdc++.h>

using namespace std;

int answer = 50;
bool visited[50];

bool compare(string& str1, string& str2)
{
    int length = str1.length(), count = 0;
    for (int i = 0; i < length; ++i)
    {
        if (str1[i] != str2[i]) ++count;
    }
    
    return (count == 1);
}

void dfs(string current, string goal, int step, vector<string>& v)
{
    if (answer <= step) return;
    if (current == goal) 
    {
        answer = min(answer, step);
        return;
    }

    for (int i = 0; i < v.size(); ++i)
    {
        if (!visited[i] && compare(current, v[i]))
        {
            visited[i] = true;
            dfs(v[i], goal, step + 1, v);
            visited[i] = false;
        }
    }
    
    return;
}

int solution(string begin, string target, vector<string> words) {
    dfs(begin, target, 0, words);
    
    return ((answer != 50) ? answer : 0);
}