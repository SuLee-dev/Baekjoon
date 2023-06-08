using namespace std;
#include <bits/stdc++.h>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    vector<string> strs(N);
    for (string& str : strs) cin >> str;
    
    vector<char> v;
    for (int i = 0; i < M; ++i)
    {
        int maxCount(0), alphabet[26] {0, };
        char ch;
        
        for (string& str : strs)
        {
            ++alphabet[str[i] - 'A'];
            maxCount = max(maxCount, alphabet[str[i] - 'A']);
        }
        
        for (int i = 0; i < 26; ++i)
        {
        	if (alphabet[i] == maxCount)
        	{
        		v.push_back(char(i + 65));
        		break;
        	}
        }
    }
    
    string result(v.begin(), v.end());
    int HD(0);
    for (string& str : strs)
    {
    	for (int i = 0; i < M; ++i)
    	{
    		if (str[i] != result[i]) ++HD;
    	}
    }
    
    cout << result << "\n" << HD;
}