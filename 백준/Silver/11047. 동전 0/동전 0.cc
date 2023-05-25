using namespace std;
#include <iostream>
#include <vector>


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    
    for (int i = 0; i < N; ++i) cin >> v[i];
    
    int result(0), length(N);
    for (int i = N - 1; i >= 0; --i)
    {
        result += K / v[i];
        K %= v[i];
    }
    
    cout << result;
}