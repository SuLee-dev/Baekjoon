#include <iostream>
#include <vector>
using namespace std;

bool prime(int x) {
	if (x == 1) return false;
	else if (x == 2) return true;
    for (int i = 2; i < x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void check(int x, int y, vector<int>& arr) {
		for (int i = x; i <= y; i++) {
			if (prime(i)) arr.push_back(i);
	}
}

int main() {
    int m, n, sum = 0;
    vector<int> v;
    cin >> m >> n;
    
    check(m, n, v);    
    
    if (v.size() == 0) {
    	cout << -1;
    	return 0;
    }
    
    for (int i : v) sum += i;
    cout << sum << endl << v.front();
    
}