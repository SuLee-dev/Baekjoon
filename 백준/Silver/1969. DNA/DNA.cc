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
    
    string result("");
    int HD(0);
    for (int i = 0; i < M; ++i)
    {
        int maxCount(0), alphabet[26] {0, };
        char ch;
        
        for (string& str : strs) ++alphabet[str[i] - 'A'];
        
        for (int i = 0; i < 26; ++i)
        {
        	if (alphabet[i] > maxCount) ch = i + 'A', maxCount = alphabet[i];
        }
        
        result += ch;
        HD += N - maxCount;
    }
    
    cout << result << "\n" << HD;
}