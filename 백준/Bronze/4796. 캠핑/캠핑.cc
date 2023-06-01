using namespace std;
#include <iostream>
#include <algorithm>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int L, P, V, caseNum(0), result(0);
    while (true)
    {
        cin >> L >> P >> V;
        if (L && P && V)
        {
            ++caseNum;
            result = V / P * L + ((V % P > L) ? L : V % P);
            cout << "Case " << caseNum << ": " << result << "\n";
        }
        else break;
    }
}