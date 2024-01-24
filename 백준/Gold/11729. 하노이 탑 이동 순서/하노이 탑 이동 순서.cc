#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

void hanoi(int start, int temp, int end, int n) {
    if (n == 1) printf("%d %d\n", start, end);
    else {
        hanoi(start, end, temp, n - 1);
        printf("%d %d\n", start, end);
        hanoi(temp, start, end, n - 1);
    }
}

void hanoiNum(int x)
{
	int num = 1;
	while (--x) {
		num = num * 2 + 1;
	}
	printf("%d\n", num);
}

int main() {
    int n; cin >> n;
    hanoiNum(n);
    hanoi(1, 2, 3, n);
}