using namespace std;
#include <iostream>
#include <algorithm>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    int arr[100000];
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N, greater<>());
    
    int result = 0;
    for (int i = 0; i < N; ++i)
    {
        int totalWeight = arr[i] * (i + 1);
        result = (result < totalWeight) ? totalWeight : result;
    }
    
    cout << result;
}