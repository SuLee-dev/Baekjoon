using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int pop(vector<int>& v)
{
	int temp = v.back();
	v.pop_back();
	return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    int result(0);
    bool haveZero(false);
    vector<int> pos, neg;
    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        
        if (input > 1) pos.push_back(input);
        else if (input == 1) ++result;
        else if (input == 0) haveZero = true;
        else neg.push_back(input);
    }
    
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<>());
    
    while (pos.size() >= 2) result += pop(pos) * pop(pos);
    while (neg.size() >= 2) result += pop(neg) * pop(neg);
    
    if (!pos.empty()) result += pop(pos);
    if (!neg.empty() && !haveZero) result += pop(neg);
    
    cout << result;
}