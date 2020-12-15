#include<bits/stdc++.h>
using namespace std;
int a[205];
int b[205];
int c[205];
int main(){
	int t, i = 0, flag = 0, len1 = 0,len2 = 0,len3;
	string sa,sb;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	cin>>sa>>sb;
	for(i = 0; i< sa.size();i++ ){
		if(flag == 0 && sa[i] == '0'&& i!=sa.size()-1) continue;
		flag = 1;
		a[len1] = sa[i]-'0';
		len1++;
	}
	flag = 0;
	for(i = 0; i< sb.size(); i++){
		if(flag == 0 && sb[i] == '0'&&i!=sb.size()-1)  continue;
		flag = 1;
		b[len2] = sb[i]-'0';
		len2++;
	}
	len3 = max(len1,len2);
	int co = 0;
	int j = len1 - 1, k = len2 - 1, t1, t2;
	for(i = len3 - 1; i >= 0; i--){
		if(j < 0) t1 = 0;
		else t1 = a[j--];
		if(k < 0) t2 = 0;
		else t2 = b[k--];
		t = t1-t2-co;
		if(t < 0){
			t+= 10;
			co = 1;
		} else{
			co = 0;
		}
		c[i] = t;
	}
	for(i =0; i < len3; i++){
		cout<<c[i];
	}
} 
