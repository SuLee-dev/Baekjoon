using namespace std;
#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    double N, B, C;
    cin >> N;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    cin >> B >> C;
    
    long long result = 0;
    for (int num : A) 
    {    
        if (num > B) result += ceil((num - B) / C) + 1;
        else result += 1;
    }
    
    cout << result;
}