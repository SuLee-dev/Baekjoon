using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
typedef pair<int, int> P;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T, N;
    cin >> T;
    
    for (int i = 0; i < T; ++i)
    {
        cin >> N;
        
        vector<P> v(N);
        for (int j = 0; j < N; ++j) cin >> v[j].first >> v[j].second;
        sort(v.begin(), v.end());
        
        int temp(100001), result(0);
        for (P p : v)
        {
            if (p.second < temp)
            {
                temp = p.second;
                ++result;
            }
        }
        
        cout << result << "\n";
    }
}