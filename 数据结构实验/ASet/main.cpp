#include "ASet.h"
/*计算1913李文轩*/ 
int main()
{
	int k,n,d;
	int a[MaxSize]={10,9,8,7,6,5,4,3,2,1},b[MaxSize]={10,45,48,2,65,8,12,5,4,63};
	cout<<"请输如数组a,b的大小(MaxSize = 30):";
	cin>>n;
	cout<<"请初始化数组a：";
	for(int i = 0; i != n; i ++) cin>>a[i];
	cout<<"请初始化数组b：";
	for(int i = 0; i != n; i ++) cin>>b[i];
	Set s1,s2,s3;
	s1.len = s2.len = s3.len = 0;
	while(1){
		system("cls");
		showmenu();
		cin>>k;
		switch(k){
			case 1:{creatS(s1,a,n);break;}
			case 2:{creatS(s2,b,n);break;}
			case 3:{showall(s1);break;}
			case 4:{showall(s2);break;}
			case 5:{cout<<"请输入d：";cin>>d;isin(s1,d);break;}
			case 6:{cout<<"请输入d：";cin>>d;isin(s2,d);break;}
			case 7:{add(s1,s2,s3);break;}
			case 8:{sub(s1,s2,s3);break;}
			case 9:{sub(s2,s1,s3);break;}
			case 10:{mul(s1,s2,s3);break;}
			case 11:{exit(0);break;}
		}
	}
	return 0;
}

void creatS(Set &s,int a[],int n)
{
	for(int i = 0; i != n; i++){
		s.data[i] = a[i];
	} 
	s.len = n;
	system("PAUSE");
}
void showall(Set s)
{
	for(int i = 0; i != s.len; i++){
		cout<<s.data[i]<<" ";
	}
	cout<<endl;
	system("PAUSE");
}
void isin(Set s,int d)
{
	int flag = 0;
	for(int i = 0; i != s.len; i++){
		if(s.data[i] == d){
			flag = 1;
			break;
		}
	}
	flag == 0?cout<<d<<"元素不在集合中\n":cout<<d<<"在集合中\n";
	system("PAUSE");
}
void add(Set s1,Set s2,Set s3){//求交集
	int num = 0; 
	for(int i = 0; i != s1.len; i++){
		for(int j = 0;j != s2.len;j++){
			if(s1.data[i] == s2.data[j]){
				s3.data[num++] = s1.data[i];
			}
		}
	}
	s3.len = num;
	showall(s3);
}
void sub(Set s1,Set s2,Set s3){//求差集 
	s3.len = 0;
	for(int i = 0; i != s1.len; i ++){
		int flag = 0;
		for(int j = 0; j != s2.len; j ++){
			if(s1.data[i] == s2.data[j]){
				flag = 1;
				break;
			}
		}
		if(flag == 0) s3.data[s3.len++] = s1.data[i]; 
	}
	showall(s3);
}
void mul(Set s1,Set s2,Set s3)//求并集 
{
	s3.len = 0;
	int num = s1.len,k=0;
	while(k!=num){
		int flag = 0;
		for(int i=0;i!=s3.len;i++){
			if(s3.data[i] == s1.data[k]){
				flag = 1;
				break;
			} 
		}
		if(flag == 0) s3.data[s3.len++] = s1.data[k];
		k++;
	}
	k = 0;
	num = s2.len;
	while(k!=num){
		int flag = 0;
		for(int i=0;i!=s3.len;i++){
			if(s3.data[i] == s2.data[k]){
				flag = 1;
				break;
			} 
		}
		if(flag == 0) s3.data[s3.len++] = s2.data[k];
		k++;
	}
	showall(s3);
}
void showmenu()
{
	printf("1.由数组a创建集合s1\n");
	printf("2.由数组b创建集合s2\n");
	printf("3.打印s1所有元素\n");
	printf("4.打印s2所有元素\n");
	printf("5.判断元素d是否在集合s1中\n");
	printf("6.判断元素d是否在集合s2中\n"); 
	printf("7.求s1,s2的交集\n");
	printf("8.求s1,s2的差集\n");
	printf("9.求s2,s1的差集\n");
	printf("10.求s1,s2的交集\n");
	printf("11.退出\n\n");
	printf("请输入操作的数字:");
}

