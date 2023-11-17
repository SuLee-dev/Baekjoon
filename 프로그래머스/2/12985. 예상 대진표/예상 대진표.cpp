#include <bits/stdc++.h>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while (a != b)
    {
        ++answer;
        a = ceil(double(a) / 2);
        b = ceil(double(b) / 2);
    }

    return answer;
}