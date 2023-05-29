using namespace std;
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
typedef pair<int, int> P;

bool cmp(P a, P b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<P> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), cmp);
    
    queue<P> q;
    q.push(v[0]);
    for (int i = 1; i < N; ++i)
    {
        if (q.back().second <= v[i].first) q.push(v[i]);
    }
    
    int result = q.size();
    cout << result;
}