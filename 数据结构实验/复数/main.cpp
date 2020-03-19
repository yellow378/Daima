/*计算1913李文轩*/ 
#include "fushu.h"
int main()
{
	int k,v1,v2,real,imag,mod;
	Fushu z1,z2,sum,mul;
	while(1){
		system("cls");
		showmenu();
		cin>>k;
		switch(k){
			case 1:{AssignComplex(z1, v1, v2);;}
			case 2:{AssignComplex(z2, v1, v2);;}
			case 3:{DestroyComplex(z1);;}
			case 4:{DestroyComplex(z2);;}
			case 5:{GetReal(z1, real);;}
			case 6:{GetReal(z2, real);;}
			case 7:{GetImag(z1, imag);;}
			case 8:{GetImag(z2, imag);;}
			case 9:{Add(z1, z2, sum);;}
			case 10:{Multiply(z1, z2, mul);;}
			case 11:{Mode(z1, mod);;}
			case 12:{Mode(z2, mod);;}
			case 13:{exit(0);;}
		}
	}
	
	return 0;	
}


void AssignComplex(Fushu &z,int v1,int v2)
{
	cout<<"请输入实部和虚部：";
	cin>>v1>>v2;
	z.real = v1;
	z.imag = v2;
	system("PAUSE");
} 
void DestroyComplex(Fushu &z)
{
	z.real = 0;
	z.imag = 0;
	system("PAUSE");
}
void GetReal(Fushu z,int &real)
{
	real = z.real;
	cout<<real<<endl; 
	system("PAUSE");
}
void GetImag(Fushu z,int &imag)
{
	imag = z.imag;
	cout<<imag<<endl;
	system("PAUSE");
}
void Add(Fushu z1,Fushu z2,Fushu  &sum)
{
	sum.real = z1.real + z2.real;
	sum.imag = z1.imag + z2.imag;
	if(sum.real) cout<<sum.real;
	if(sum.real&&sum.imag) cout<<" + ";
	if(sum.imag) cout<<sum.imag<<"i";
	cout<<endl;
	system("PAUSE");
}
void Multiply(Fushu z1,Fushu z2,Fushu&mul)
{
	
	mul.real = z1.real * z2.real + z1.imag * z2.imag;
	mul.imag = z1.real * z2.imag + z2.real * z1.imag;
	if(mul.real) cout<<mul.real;
	if(mul.real&&mul.imag) cout<<" + ";
	if(mul.imag) cout<<mul.imag<<"i";
	cout<<endl;
	 
	system("PAUSE");
}
void Mode(Fushu z,int &mod)
{
	mod = (z.real * z.real + z.imag * z.imag);
	cout<<mod<<endl;
	system("PAUSE");
}
void showmenu()
{
	printf("1.构造复数z1\n");
	printf("2.构造复数z2\n\n");
	printf("3.撤销复数z1\n");
	printf("4.撤销复数z2\n\n");
	printf("5.返回复数z1实部\n");
	printf("6.返回复数z2实部\n\n");
	printf("7.返回复数z1虚部\n");
	printf("8.返回复数z2虚部\n\n");
	printf("9.返回两复数和\n");
	printf("10.返回两复数乘积\n\n");
	printf("11.返回复数z1的模的平方\n");
	printf("12.返回复数z2的模的平方\n\n");
	printf("13.退出\n\n");
	printf("请输入要进行的操作："); 
}
