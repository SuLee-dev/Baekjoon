#include <bits/stdc++.h>
using namespace std;

int N, M, result = INT_MAX;
vector<pair<int, int>> house, chicken, remain;
bool visited[13] { false, };
int dx[4] { 0, 0, 1, -1 }, dy[4] { 1, -1, 0, 0 };

void Delete(int idx, int cnt)
{
    if (cnt == M)
    {
        int distance, TotalDistance = 0;
        for (auto& h : house)
        {
            distance = INT_MAX;
            for (auto& r : remain)
            {
                distance = min(distance, abs(h.first - r.first) + abs(h.second - r.second));
            }
            TotalDistance += distance;
        }
        
        result = min(result, TotalDistance);
        return;
    }
    
    for (int i = idx; i < chicken.size(); ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            remain.push_back(chicken[i]);
            Delete(i + 1, cnt + 1);
            visited[i] = false;
            remain.pop_back();
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    cin >> N >> M;
    int input;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> input;
            if (input == 2) chicken.push_back({ i, j });
            else if (input == 1) house.push_back({ i, j });
        }
    }
    
    Delete(0, 0);
    cout << result << endl;
}