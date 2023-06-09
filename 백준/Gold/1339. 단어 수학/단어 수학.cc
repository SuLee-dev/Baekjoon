#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define ioboost ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int N, ans;
string word[10];
int alphabet[26];

bool Compare(int a, int b) { return a > b; }

void Input()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> word[i];
}

void Solve()
{
    for (int i = 0; i < N; ++i)
    {
        int pow = 1;
        string str = word[i];
        int l = str.size();
        
        for (int j = l - 1; j >= 0; --j)
        {
            int temp = str[j] - 'A';
            alphabet[temp] += pow;
            pow *= 10;
        }
    }
    
    sort(alphabet, alphabet + 26, Compare);
    
    int num = 9;
    for (int i = 0; i < 10; ++i)
    {
        if (alphabet[i] == 0) break;
        ans += alphabet[i] * num;
        --num;
    }
    
    cout << ans << '\n';
}


int main()
{
    ioboost;
    Input();
    Solve();
}