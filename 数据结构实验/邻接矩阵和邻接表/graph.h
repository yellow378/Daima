#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;
#define MaxSize 100
#define MAXV 20 //最大顶点个数
int Visted[MAXV];

typedef int InfoType;
//无权图的邻接矩阵数据结构
typedef struct{
	int no;
}VertexType;
typedef struct{
	int edges[MAXV][MAXV];
	int n,e;
	VertexType vexs[MAXV];
}MatGraph;	

//无权图邻接表的数据结构
typedef struct ANode{
	int adjvex;
	struct ANode *nextarc;
}ANode;
typedef struct Vnode{ 
	ANode *firstarc;
}VNode;
typedef struct{
	VNode adjlist[MAXV];
	int n,e;
}AdjGraph;

void CreateMat(MatGraph *&G);
void CreateAdj(AdjGraph*& G);
void DispMat(MatGraph *G);
void DispAdj(AdjGraph *G);
void BFS(AdjGraph* G,int v);
void DFSNoRe(AdjGraph* G,int v);
void DFSRe(AdjGraph* G, int v);
void PathAll(AdjGraph* G, int u, int v, int path[], int i);
void PathAlli(AdjGraph* G, int u, int v, int path[], int d, int i);
void DestoryMat(MatGraph* G);
void DestoryAdj(AdjGraph* G);
void menu();
//6 12
//0 1
//0 3
//1 2
//2 0
//2 5
//3 2
//3 5
//4 3
//5 0
//5 1
//5 3
//5 4