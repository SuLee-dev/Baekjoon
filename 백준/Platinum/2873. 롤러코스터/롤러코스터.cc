#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int R, C;
    cin >> R >> C;
    
    vector<vector<int>> map(R, vector<int>(C));
    int input, lowest(1001), minX(0), minY(0);
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> input;
            map[i][j] = input;
            if (lowest > input && (i + j) % 2 == 1)
            {
                minX = j;
                minY = i;
                lowest = input;
            }
        }
    }
    
    string result;
    if (R % 2)
    {
        for (int i = 0; i < R / 2; ++i)
        {
            result += string(C - 1, 'R') + "D" + string(C - 1, 'L') + "D";
        }
        result += string(C - 1, 'R');
        cout << result;
    }
    else if (C % 2)
    {
        for (int i = 0; i < C / 2; ++i)
        {
            result += string(R - 1, 'D') + "R" + string(R - 1, 'U') + "R";
        }
        result += string(R - 1, 'D');
        cout << result;
    }
    else
    {    
        for (int i = 0; i < minX / 2; ++i)
        {
            result += string(R - 1, 'D') + "R" + string(R - 1, 'U') + "R";
        }
        
        int xBound = (minX / 2) * 2 + 1;
        int x = (minX / 2) * 2;
        int y = 0;
        while (x != xBound || y != R - 1)
        {
            if (x < xBound && (x + 1 != minX || y != minY))
            {
                ++x;
                result += "R";
            }
            else if (x == xBound && (x - 1 != minX || y != minY))
            {
                --x;
                result += "L";
            }
            
            if (y != R - 1)
            {
                ++y;
                result += "D";
            }
        }
        
        for (int i = xBound + 1; i < C; i += 2)
        {
            result += "R" + string(R - 1, 'U') + "R" + string(R - 1, 'D');
        }
        
        cout << result;
    }
}