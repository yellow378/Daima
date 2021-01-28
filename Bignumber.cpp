#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

#define Maxn 3000

typedef struct Bignumber {

	int len;
	int v[Maxn];

	Bignumber() {
		len = 0;
		memset(v, 0, sizeof(v));
	}
	Bignumber(int in) {
		memset(v, 0, sizeof(v));
		*this = in;
	}
	Bignumber(string in) {
		memset(v, 0, sizeof(v));
		*this = in;
	}
	Bignumber operator = (string in) {		
		len = in.length();
		for (int i = 0; i < len; i++) {
			v[i] = in[len - i - 1] - '0';
		}
		return *this;
	}
	Bignumber operator = (int in) {
		len = 0;
		while (in != 0) {
			v[len++] = in % 10;
			in /= 10;
		}
		return *this;
	}
	Bignumber operator + (const Bignumber &b) const{
		Bignumber c;
		c.len = 0;
		for (int i = 0, g = 0; g || i < max(len, b.len); i++) {
			int t = v[i] + b.v[i] + g;
			c.v[c.len++] = t % 10;
			g = t / 10;
		}
		return c;
	}
	Bignumber operator - (const Bignumber& b) const {
		Bignumber c;
		c.len = 0;
		for (int i = 0, g = 0; g || i < max(len, b.len); i++) {
			int t = v[i] - b.v[i] - g;
			if (t < 0) {
				t += 10;
				g = 1;
			}else{
				g = 0;
			}
			c.v[c.len++] = t % 10;
		}
		while (c.v[c.len - 1] == 0) {
			c.len--;
		}
		return c;
	}
	Bignumber operator * (const Bignumber& b) const {
		Bignumber c;
		c.len = 0;
		if(len == 0 || b.len == 0) return c;
		for (int i = 0; i < b.len; i++) {
			for (int j = 0, g = 0; g || j < len; j++) {
				int a = v[j] * b.v[i] + g + c.v[j + i];
				c.v[j + i] = a % 10;
				g = a / 10;
				c.len = j + i > c.len ? j + i : c.len;
			}
		}
		c.len++;
		return c;
	}
	Bignumber operator / (const Bignumber& b) const {
		Bignumber temp = *this;
		Bignumber c;
		Bignumber big10 = 10;
		Bignumber big1 = 1;
		c.len = 0;
		if( b.len > len){
				return c; 
		}
		int size = len - b.len;
		for(int i = size; i >= 0; i--){
				Bignumber t = b;
				for(int j = 0; j < i; j++){
						t = t * big10;
				}
				c = c * big10;
				while(temp >= t){
						temp = temp - t;
						c = c + big1;
				}
		}
		return c;
	}
	Bignumber operator % (const Bignumber& b) const {
		return *this - (*this / b * b) ;
	}
	bool operator > (const Bignumber& b) const {
		if (len > b.len) return true;
		if (len < b.len) return false;
		for (int i = len - 1; i >=0; i--) {
			if (v[i] > b.v[i]) return true;
			else if (v[i] < b.v[i]) return false;
		}
		return false;
	}
	bool operator < (const Bignumber& b) const {
		if (len < b.len) return true;
		if (len > b.len) return false;
		for (int i = len - 1; i >= 0; i--) {
			if (v[i] < b.v[i]) return true;
			else if (v[i] > b.v[i]) return false;
		}
		return false;
	}
	bool operator == (const Bignumber& b) const {
		if (len != b.len) return false;
		for (int i = 0; i < len; i++) {
			if (v[i] != b.v[i]) return false;
		}
		return true;
	}
	bool operator >= (const Bignumber& b) const {
		return *this > b || *this == b;
	}
	bool operator <= (const Bignumber& b) const {
		return *this < b || *this == b;
	}
	string str() const{ 
		string res = "";
		for (int i = 0; i < len; i++) {
			res = (char)(v[i] + '0') + res;
		}
		if (res == "") return "0";
		return res;
	}
}bign;
string a = "783419247214";//100000000000000000000
string b = "9";
bign c = a;
bign d = b;
bign e = c % d;
int main(){
	
	cout <<a<<endl<<d.str()<<endl<< e.str() << endl;
	//a > b ? cout << "dayu" : cout << "not dayu";
}
