using namespace std;
#include <iostream>

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    int result = 0;
    if (M < 7)
    {
        switch (N)
        {
            case 1:
                result = 1;
                break;
            case 2:
                result = (M + 1) / 2;
                break;
            default:
                result = (M > 4) ? 4 : M;
                break;
        }
    }
    else
    {
        switch (N)
        {
            case 1:
                result = 1;
                break;
            case 2:
                result = 4;
                break;
            default:
                result = M - 2;       
                break;
        }
    }
    
    cout << result;
}