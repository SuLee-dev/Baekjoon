#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = string(1, toupper(s[0]));
    
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i - 1] == ' ' && s[i] != ' ' && !isdigit(s[i])) 
        {
            answer += toupper(s[i]);
            continue;
        }
        answer += tolower(s[i]);
    }
    
    return answer;
}