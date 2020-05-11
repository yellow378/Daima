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


2. 中序遍历和后序遍历转前序遍历
~~~c
   #include<string.h>
   #include<iostream>
   #define MaxSize 100
   using namespace std;
   
   void PreTrans(char* in, char* pos, int n) {
   	if (n < 0) return;
   	if (n == 0) {
   		cout << pos[n];
   		return;
   	}
   	printf("%c", *(pos + n));
   	int p;
   	for (p = 0; p < n; p++) {
   		if (in[p] == pos[n]) break;
   	}
   	PreTrans(in, pos, p - 1);
   	PreTrans(in + p + 1, pos + p, n - 1 - p);
   }
   
   int main()
   {
   	char pos[MaxSize];
   	char in[MaxSize];
   	fgets(in, sizeof(in), stdin);
   	fgets(pos, sizeof(pos), stdin);
   	int len = strlen(in);
   	PreTrans(in, pos, len - 2);
   	return 0;
   }
~~~

3. 