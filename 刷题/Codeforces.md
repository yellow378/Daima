1. [Div4  K-th Not Divisible by n](https://codeforces.com/contest/1352/problem/C)
~~~c
#include<iostream>
using namespace std;
int main()
{
	int k;
	cin >> k;
	while (k--) {
		int n, k;
		cin >> n >> k;
		int n1 = n - (k - 1);
		if (n1 > 0 && n1 & 1) {
			cout << "YES" << endl;
			for (int i = 0; i < k - 1; i++) {
				cout << "1 ";
			}
			cout << n1<<endl;
			continue;
		}
		int n2 = n - 2*(k - 1);
		if (n2 > 0 && !(n2 & 1)) {
			cout << "YES" << endl;
			for (int i = 0; i < k - 1; i++) {
				cout << "2 ";
			}
			cout << n2<<endl;
			continue;
		}
		cout << "NO" << endl;
	}
	return 0;
}
~~~