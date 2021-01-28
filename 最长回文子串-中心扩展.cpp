#include<iostream>
#include<string>
using namespace std;
#define MAXSIZE 1000
int p[MAXSIZE];
char ss[MAXSIZE];
int main(){
	
	//最长回文子串，中心扩张
	int max = -1;			//回文子串长度
	int x = 0, y = 0;		//回文子串开始和结束位置
	string s;
	getline(cin,s);
	int length = s.length();

	//数据预处理
	int j = 0;
	for (int i = 0; i < length; i++) {
		if (isalpha(s[i])) {
			ss[j] = toupper(s[i]);
			p[j++] = i;
		}
	}
	int m = j;				//实际的字母个数

	for (int i = 0; i < m; i++) {
		for (int j = 1; i - j >= 0 && i + j < m; j++) {
			if (ss[i - j] != ss[i + j]) break;
			if ((2 * j + 1) > max) {
				max = 2 * j + 1;
				x = i - j;
				y = i + j;
			}
		}
		for (int j = 0; i - j >= 0 && i + j < length; j++) {
			if (ss[i - j] != ss[i + j + 1]) break;
			if ((2 * j + 2) > max) {
				max = 2 * j + 2;
				x = i - j;
				y = i + j + 1;
			}
		}
	}
	//输出
	if (x == -1) {
		cout << "No Answer" << endl;
	}
	else {
		x = p[x], y = p[y];
		cout << max << endl;
		for (int i = x; i <= y; i++) {
			cout << s[i];
		}
	}
	
	return 0;
}