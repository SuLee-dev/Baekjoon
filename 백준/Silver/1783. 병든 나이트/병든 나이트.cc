using namespace std;
#include <iostream>
#include <algorithm>

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    
    int result = 0;
    
    switch (N)
    {
        case 1:
            result = 1;
            break;
        case 2:
            result = min(4, (M + 1) / 2);
            break;
        default:
            result = (M < 7) ? min(4, M) : M - 2;
    }
    
    cout << result;
}