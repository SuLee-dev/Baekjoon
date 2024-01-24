#include <bits/stdc++.h>
using namespace std;

int N;
int Image[64][64] { 0, };

bool Check(int n, int x, int y)
{
    bool ZeroFlag = true;
    if (Image[x][y] == 1) ZeroFlag = false;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (ZeroFlag && Image[x + i][y + j] == 1) return false;
            else if (!ZeroFlag && Image[x + i][y + j] == 0) return false;
        }
    }
    
    return true;
}

void QuadTree(int n, int x, int y)
{
    if (Check(n, x, y)) 
    {
    	cout << Image[x][y];
    	return;
    }
    
    cout << "(";
    QuadTree(n / 2, x, y);
    QuadTree(n / 2, x, y + n / 2);
    QuadTree(n / 2, x + n / 2, y);
    QuadTree(n / 2, x + n / 2, y + n / 2);
    cout << ")";
}

int main()
{
    cin >> N;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        for (int j = 0; j < N; ++j)
	        Image[i][j] = str[j] - '0';
    }
    
    QuadTree(N, 0, 0);
}