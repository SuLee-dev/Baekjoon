using namespace std;
#include <bits/stdc++.h>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    vector<int> v(K);
    for (int i = 0; i < K; ++i) cin >> v[i];
    
    vector<int> mt;
    int result(0);
    for (auto v_it = v.begin(); v_it != v.end(); ++v_it)
    {    
        auto mt_it = find(mt.begin(), mt.end(), *v_it);
        if (mt_it != mt.end()) continue;
        else if (mt.size() < N)  mt.push_back(*v_it);
        else
        {
            ++result;
            int out(0), outidx(0);
            for (int i = 0; i < N; ++i)
            {
                auto f_it = find(v_it + 1, v.end(), mt[i]);
                if (f_it != v.end())
                {
                    if (f_it - v.begin() > outidx)
                    {
                        out = i;
                        outidx = f_it - v.begin();
                    }
                }
                else
                {
                	out = i;
                	break;
                }
            }
            
            mt[out] = *v_it;
        }
    }
    
    cout << result;
}