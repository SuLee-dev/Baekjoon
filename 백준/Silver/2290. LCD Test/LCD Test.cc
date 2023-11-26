#include <bits/stdc++.h>
using namespace std;

void DrawVertical(int n, int space, vector<string>& v)
{
    for (int i = 1; i < space + 1; ++i)
    {
        switch (n)
        {
            case 1:
            case 2:
            case 3:
            case 7:
                v[i].append(string(space + 1, ' ') + "|" + " ");
                break;
            case 5:
            case 6:
                v[i].append("|" + string(space + 1, ' ') + " ");
                break;
            case 4:
            case 8:
            case 9:
            case 0:
                v[i].append("|" + string(space, ' ') + "|" + " ");
                break;
        }
    }
    
    for (int i = space + 2; i < 2 * space + 2; ++i)
    {
        switch (n)
        {
            case 1:
            case 3:
            case 4:
            case 5:
            case 7:
            case 9:
                v[i].append(string(space + 1, ' ') + "|" + " ");
                break;
            case 2:
                v[i].append("|" + string(space + 1, ' ') + " ");
                break;
            case 6:
            case 8:
            case 0:
                v[i].append("|" + string(space, ' ') + "|" + " ");
                break;
        }
    }
}

void DrawHorizontal(int n, int space, vector<string>& v)
{
    switch (n)
    {
        case 1:
        case 4:
            v[0].append(string(space + 2, ' ') + " ");
            break;
        default:
            v[0].append(" " + string(space, '-') + " " + " ");
            break;
    }
    
    switch (n)
    {
        case 1:
        case 7:
        case 0:
            v[space + 1].append(string(space + 2, ' ') + " ");
            break;
        default:
            v[space + 1].append(" " + string(space, '-') + " " + " ");
            break;
    }
    
    switch (n)
    {
        case 1:
        case 4:
        case 7:
            v[2 * space + 2].append(string(space + 2, ' ') + " ");
            break;
        default:
            v[2 * space + 2].append(" " + string(space, '-') + " " + " ");
    }
}

int main()
{
    int s; string n;
    cin >> s >> n;
    
    vector<string> lines(2 * s + 3);
    for (char& c : n)
    {
        int num = c - '0';
        DrawVertical(num, s, lines);
        DrawHorizontal(num, s, lines);
    }
    
    for (string& str : lines) cout << str << endl;
}
