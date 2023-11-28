#include <bits/stdc++.h>
using namespace std;

int M, N, H, result = 0;
vector<int> v;
int BOX[1000000] { 0, };
int dx[6] { 0, 0, 0, 0, -1, 1 }, dy[6] { 0, 0, -1, 1, 0, 0 }, dz[6] { -1, 1, 0, 0, 0, 0 };

void BFS()
{
    queue<vector<int>> q;
    q.push(v);
    
    while (true)
    {
        vector<int> Old = q.front();
        q.pop();
        
        vector<int> New;
        for (int& idx : Old)
        {
            int X = (idx % (M * N)) % M;
            int Y = (idx % (M * N)) / M;
            int Z = idx / (M * N);
            
            for (int i = 0; i < 6; ++i)
            {
                int nX = X + dx[i];
                int nY = Y + dy[i];
                int nZ = Z + dz[i];
                
                if (nX < 0 || nX >= M || nY < 0 || nY >= N || nZ < 0 || nZ >= H) continue;
                int newIdx = nX + nY * M + nZ * (M * N);
                if (BOX[newIdx] == 0)
                {
                    BOX[newIdx] = 1;
                    New.push_back(newIdx);
                }
            }
        }
        
        if (New.empty()) break;
        q.push(New);
        ++result;
    }
}

int main()
{
    memset(BOX, -1, sizeof(BOX));
    
    cin >> M >> N >> H;
    int input, emptyCell = 0;
    for (int i = 0; i < M * N * H; ++i)
    {
        cin >> input;
        BOX[i] = input;
        if (input == 1) v.push_back(i);
        else if (input == 0) ++emptyCell;
    }
    
    if (emptyCell == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    
    BFS();
    for (int& idx : BOX)
    {
        if (idx == 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << result << endl;
}