//����1913������
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
#define MaxSize 100
//���ݽṹ
typedef struct {
	int r;			//��
	int c;			//��
	int data;		//����
}ThreeTup;

typedef struct {
	int rows;				//����
	int cols;				//����
	int nums;				//����Ԫ����
	ThreeTup data[MaxSize];	//����
}TupMatrix;

void CreateTupMatrix(TupMatrix &t,int n, int m);
void PrintTupMatrix(TupMatrix t);
void AddTupMatrix(TupMatrix a, TupMatrix b, TupMatrix& c);
void TranTupMatrix(TupMatrix a, TupMatrix b, TupMatrix& at, TupMatrix &bt);
int GetValue(TupMatrix a, int i, int j);
void MultTupMatrix(TupMatrix a, TupMatrix b, TupMatrix& c);
void menu();
/*
1 0 3 0
0 1 0 0
0 0 1 0
0 0 1 1
-------
3 0 0 0
0 4 0 0
0 0 1 0
0 0 0 2
*/