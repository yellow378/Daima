/*
计算1913李文轩 
ADT Complex {
    数据对象：D={e1,e2|e1,e2均为实数}    //复数的形式：e1+e2i或者(e1, e2)
    数据关系：R={<e1,e2>|e1是复数的实部，e2是复数的虚部}
    基本运算：
        AssignComplex(&z, v1, v2)
          	操作结果：构造复数z, 其实部和虚部分别为参数v1和v2的值。
        DestroyComplex(&z)
          	操作结果：复数z被撤销。
        GetReal(z, &real)
          	操作结果：用real返回复数z的实部值。
        GetImag(z, &imag)
          	操作结果：用imag返回复数的虚部值。
        Add(z1, z2, &sum)
          	操作结果：用sum返回两个复数z1、z2相加的结果。
        Multiply(z1, z2, &mul)
        	操作结构：用sum返回两个复数z1, z1相乘的结果
        Mode(z, &mod)
        	操作结果：用mod返回复数的模    
}ADT Complex
*/
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
typedef struct fushu{
	int real;
	int imag;
}Fushu;
void AssignComplex(Fushu &z,int v1,int v2); 
void DestroyComplex(Fushu &z);
void GetReal(Fushu z,int &real);
void GetImag(Fushu z,int &imag);
void Add(Fushu z1,Fushu z2,Fushu  &sum);
void Multiply(Fushu z1,Fushu z2,Fushu&mul);
void Mode(Fushu z,int &mod);
void showmenu();
