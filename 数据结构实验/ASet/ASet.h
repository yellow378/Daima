/*����1913������ 
ADT ASet {
	���ݶ���D={a0,a1,a2....an-1|��Ϊ������}
	���ݹ�ϵ���޹�ϵ 
	�������� �� creatS(&s,a,n) 
				������a����һ������ 
				showall(s)
				�����������Ԫ�� 
				isin(s,d)
				�ж�һ��Ԫ���Ƿ���һ�������� 
				add(s1,s2,s3)
				���������ϵĲ��� 
				sub(s1,s2,s3)
				���������ϵĲ 
				mul(s1,s2,s3)
				���������ϵĽ��� 
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

