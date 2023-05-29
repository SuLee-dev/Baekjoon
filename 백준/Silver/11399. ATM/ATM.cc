using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int N;
    cin >> N;
    
    vector<int> v(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    
    int result(0), sum(0);
    for (int num : v)
    {
        sum += num;
        result += sum;
    }
    
    cout << result;
}