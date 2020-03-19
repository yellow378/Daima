/*计算1913李文轩 
ADT ASet {
	数据对象：D={a0,a1,a2....an-1|均为正整数}
	数据关系：无关系 
	基本运算 ： creatS(&s,a,n) 
				由数组a创建一个集合 
				showall(s)
				输出集合所有元素 
				isin(s,d)
				判断一个元素是否在一个集合中 
				add(s1,s2,s3)
				求两个集合的并集 
				sub(s1,s2,s3)
				求两个集合的差集 
				mul(s1,s2,s3)
				求两个集合的交集 
} ADT ASet
*/
#include<iostream>
#define MaxSize 30
using namespace std;

typedef struct {
	int data[MaxSize];
	int len;
}Set; 
void creatS(Set &s,int a[],int n);
void showall(Set s);
void isin(Set s,int d);
void add(Set s1,Set s2,Set s3);
void sub(Set s1,Set s2,Set s3);
void mul(Set s1,Set s2,Set s3);
void showmenu();

