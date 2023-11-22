#include <bits/stdc++.h>

using namespace std;

int changeTime(string str)
{
    istringstream iss(str);
    string buffer;
    vector<int> v;
    
    while (getline(iss, buffer, ':'))
    {
        v.push_back(stoi(buffer));
    }
    
    return 60 * v.front() + v.back();
}

vector<int> split(string str)
{
    istringstream iss(str);
    string buffer;
    vector<int> result;
    
    while (getline(iss, buffer, ' '))
    {
        if (result.empty()) result.push_back(changeTime(buffer));
        else
        {
            try
            {
                result.push_back(stoi(buffer));
            }
            catch (...)
            {
                break;
            }
        }
    }
    
    return result;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    int BaseTime = fees[0], BaseFee = fees[1];
    int UnitTime = fees[2], UnitFee = fees[3];
    
    map<int, queue<int>> TimeTable;
    for (string& record : records)
    {
        vector<int> nums = split(record);
        TimeTable[nums.back()].push(nums.front());
    }
    
    for (auto it = TimeTable.begin(); it != TimeTable.end(); ++it)
    {
        queue<int> q = (*it).second;
        if (q.size() % 2 == 1) q.push(60 * 23 + 59);
        
        int UsedTime = 0;
        while (!q.empty())
        {
            int InTime = q.front();
            q.pop();
            int OutTime = q.front();
            q.pop();
             
            UsedTime += (OutTime - InTime);
        }

        int TotalFee = (UsedTime > BaseTime ? ceil(double(UsedTime - BaseTime) / UnitTime) * UnitFee + BaseFee : BaseFee);
        answer.push_back(TotalFee);
    }
    
    return answer;
}