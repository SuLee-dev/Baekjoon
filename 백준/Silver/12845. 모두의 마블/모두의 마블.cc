using namespace std;
#include <iostream>
#include <algorithm>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int L[1000];
    for (int i = 0; i < n; ++i) cin >> L[i];
    sort(L, L + n, greater<>());
    
    int result(0);
    for (int i = 1; i < n; ++i) result += (L[0] + L[i]);
    
    cout << result;
}