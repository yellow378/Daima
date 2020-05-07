//计算1913李文轩
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
#define MaxSize 100
//数据结构
typedef struct {
	int r;			//行
	int c;			//列
	int data;		//数据
}ThreeTup;

typedef struct {
	int rows;				//行数
	int cols;				//列数
	int nums;				//非零元素数
	ThreeTup data[MaxSize];	//数据
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