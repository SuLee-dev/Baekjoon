#include <bits/stdc++.h>

using namespace std;

bool compare(string& str1, string& str2)
{
    int length = str1.length(), count = 0;
    for (int i = 0; i < length; ++i)
    {
        if (str1[i] != str2[i]) ++count;
    }
    
    return (count == 1);
}

int dfs(string current, string goal, int result, vector<bool>& check, vector<string>& v)
{
    if (current == goal) return result;

    for (int i = 0; i < v.size(); ++i)
    {
        if (!check[i] && compare(current, v[i]))
        {
            check[i] = true;
            int pathResult = dfs(v[i], goal, result + 1, check, v);
            if (pathResult > 0) return pathResult;
            check[i] = false;
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    if (find(words.begin(), words.end(), target) == words.end()) return 0;
    
    vector<bool> visited(words.size());
    return dfs(begin, target, 0, visited, words);
}