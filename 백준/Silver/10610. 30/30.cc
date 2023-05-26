using namespace std;
#include <iostream>
#include <string>
#include <algorithm>

int main()
{ 
    string N;
    cin >> N;
    
    sort(N.begin(), N.end(), greater<>());
    int sum(0);
    for (char ch : N) sum += ch - '0';
    if (N[N.length() - 1] - '0' || sum % 3) cout << -1;
    else cout << N;
}