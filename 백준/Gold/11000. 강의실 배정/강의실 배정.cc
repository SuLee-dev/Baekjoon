using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
typedef pair<int, int> P;

bool cmp(P a, P b)
    {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<P> time(N);
    for (int i = 0; i < N; ++i) cin >> time[i].first >> time[i].second;
    sort(time.begin(), time.end(), cmp);
       
    int result(1);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(time[0].second);
    for (int i = 1; i < N; ++i)
    {
        pq.push(time[i].second);
        if (time[i].first < pq.top()) ++result;
        else pq.pop();
    }
    
    cout << result;
}