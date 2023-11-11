#include <bits/stdc++.h>

using namespace std;

int countOne(string str)
{
    int result = 0;
    
    for (char& c : str)
    {
        if (c == '1') ++result;
    }
    
    return result;
}

string binaryChange(int i)
{
    string result = "";
    
    while (i != 0)
    {
        result = result + to_string(i % 2);
        i /= 2;
    }
    
    return result;
}

int solution(int n) {
    int answer = 0;
    int ones = countOne(binaryChange(n));
    
    for (int i = n + 1;;++i)
    {
        if (ones == countOne(binaryChange(i)))
        {
            answer = i;
            break;
        }
    }
    
    return answer;
}