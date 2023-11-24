#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    int length = prices.size();
    vector<int> answer(length);
    stack<pair<int, int>> s;
    
    for (int i = length - 1; i >= 0; --i)
    {
        
        while (!s.empty() && prices[i] <= s.top().second) s.pop();
        
        if (s.empty()) answer[i] = length - i - 1;
        else answer[i] = s.top().first - i;
        
        s.push(make_pair(i, prices[i]));
    }
    
    return answer;
}