#include "ASet.h"
/*����1913������*/ 
int main()
{
	int k,n,d;
	int a[MaxSize]={10,9,8,7,6,5,4,3,2,1},b[MaxSize]={10,45,48,2,65,8,12,5,4,63};
	cout<<"����������a,b�Ĵ�С(MaxSize = 30):";
	cin>>n;
	cout<<"���ʼ������a��";
	for(int i = 0; i != n; i ++) cin>>a[i];
	cout<<"���ʼ������b��";
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
			case 5:{cout<<"������d��";cin>>d;isin(s1,d);break;}
			case 6:{cout<<"������d��";cin>>d;isin(s2,d);break;}
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
	flag == 0?cout<<d<<"Ԫ�ز��ڼ�����\n":cout<<d<<"�ڼ�����\n";
	system("PAUSE");
}
void add(Set s1,Set s2,Set s3){//�󽻼�
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
void sub(Set s1,Set s2,Set s3){//�� 
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
void mul(Set s1,Set s2,Set s3)//�󲢼� 
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
	printf("1.������a��������s1\n");
	printf("2.������b��������s2\n");
	printf("3.��ӡs1����Ԫ��\n");
	printf("4.��ӡs2����Ԫ��\n");
	printf("5.�ж�Ԫ��d�Ƿ��ڼ���s1��\n");
	printf("6.�ж�Ԫ��d�Ƿ��ڼ���s2��\n"); 
	printf("7.��s1,s2�Ľ���\n");
	printf("8.��s1,s2�Ĳ\n");
	printf("9.��s2,s1�Ĳ\n");
	printf("10.��s1,s2�Ľ���\n");
	printf("11.�˳�\n\n");
	printf("���������������:");
}

