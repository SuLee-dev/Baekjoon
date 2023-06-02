using namespace std;
#include <iostream>
#include <string>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str;
    cin >> str;
    
    bool isMinus(false);
    int num(0), result(0);
    for (int i = 0; i <= str.length(); ++i)
    {
        if (str[i] == '+' || str[i] == '-' || i == str.length())
        {
            if (isMinus) result -= num;
            else result += num;
            
            num = 0;
            if (str[i] == '-') isMinus = true;
        }
        else num = num * 10 + (str[i] - '0');
    }
    
    cout << result;
}