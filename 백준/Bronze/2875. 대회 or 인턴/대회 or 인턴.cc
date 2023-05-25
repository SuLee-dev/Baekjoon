using namespace std;
#include <iostream>
#define endl "\n"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, K;
    cin >> N >> M >> K;
    
    int result(0);
    while (N + M >= K + 3 && N >= 2 && M >= 1)
    {
        N -= 2;
        M -= 1;
        result += 1;
    }
    
    cout << result;
}