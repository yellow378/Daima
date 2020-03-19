/*
����1913������ 
ADT Complex {
    ���ݶ���D={e1,e2|e1,e2��Ϊʵ��}    //��������ʽ��e1+e2i����(e1, e2)
    ���ݹ�ϵ��R={<e1,e2>|e1�Ǹ�����ʵ����e2�Ǹ������鲿}
    �������㣺
        AssignComplex(&z, v1, v2)
          	������������츴��z, ��ʵ�����鲿�ֱ�Ϊ����v1��v2��ֵ��
        DestroyComplex(&z)
          	�������������z��������
        GetReal(z, &real)
          	�����������real���ظ���z��ʵ��ֵ��
        GetImag(z, &imag)
          	�����������imag���ظ������鲿ֵ��
        Add(z1, z2, &sum)
          	�����������sum������������z1��z2��ӵĽ����
        Multiply(z1, z2, &mul)
        	�����ṹ����sum������������z1, z1��˵Ľ��
        Mode(z, &mod)
        	�����������mod���ظ�����ģ    
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
