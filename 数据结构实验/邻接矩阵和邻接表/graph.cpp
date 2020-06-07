//����1913������
#include "graph.h"

int main()
{
	MatGraph* G;
	AdjGraph* J;
	int k;
	while (1) {
		menu();
		scanf("%d", &k);
		switch (k) {
		case 1: {
			system("cls");
			printf("�ڽӾ���\n");
			CreateMat(G);
			DispMat(G);
			system("PAUSE");
			system("cls");
			printf("�ڽӱ�\n");
			CreateAdj(J);
			DispAdj(J);
			system("PAUSE");
			break;
		}
		case 2: {
			printf("���ĸ��㿪ʼ:");
			int v;
			scanf("%d", &v);
			printf("�ǵݹ�DFS:\t");
			DFSNoRe(J,v);
			printf("�ݹ�DFS:\t");
			for (int i = 0; i < MAXV; i++)
				Visted[i] = 0;
			DFSRe(J,v);
			printf("\n");
			system("PAUSE");
			break;
		}
		case 3: {
			printf("���ĸ��㿪ʼ:");
			int v;
			scanf("%d", &v);
			BFS(J, v);
			system("PAUSE");
			break;
		}
		case 4: {
			printf("���ĸ��㵽�ĸ���:");
			int u, v;
			scanf("%d%d", &u, &v);
			int d = -1, path[MAXV] = { 0 };
			printf("����Ϊ����:");
			int a;
			scanf("%d", &a);
			for (int i = 0; i < MAXV; i++)
				Visted[i] = 0;
			PathAlli( J, u, v, path,d,a);
			system("PAUSE");
			break;
		}
		case 5: {
			printf("���ĸ��㵽�ĸ���:");
			int u, v;
			scanf("%d%d", &u, &v);
			int d = -1, path[MAXV] = { 0 };
			for (int i = 0; i < MAXV; i++)
				Visted[i] = 0;
			PathAll(J, u, v, path, d);
			system("PAUSE");
			break;
		}
		case 6: {
			DestoryMat(G);
			DestoryAdj(J);
			system("PAUSE");
			break;
		}
		case 7: {
			exit(0);
			break;
		}
		}
	}
	return 0;	
}
void CreateMat(MatGraph *&G){
	G = (MatGraph*)malloc(sizeof(MatGraph));
	int n,e,start,end;
	scanf("%d%d", &n, &e);
	G->n = n, G->e = e;
	for (int i = 0; i < n; i++) {
		G->vexs[i].no = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G->edges[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++) {
		scanf("%d%d", &start, &end);
		G->edges[start][end] = 1;
	}
	//printf("G->n=%d\n", G->n);
}
void CreateAdj(AdjGraph *&G){
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	int n, e;
	scanf("%d%d", &n, &e);
	//printf("%d %d\n", n, e);
	G->n = n, G->e = e;
	ANode *p;
	for(int i=0;i<n;i++){
		G->adjlist[i].firstarc=NULL;
	}
	int A[MAXV][MAXV] = { 0 };
	int start, end;
	for (int i = 0; i < e; i++) {
		scanf("%d%d", &start, &end);
		A[start][end] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (A[i][j] != 0) {
				p = (ANode*)malloc(sizeof(ANode));
				p->adjvex = j;
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		}
	}
}
void DispMat(MatGraph *G) {
	//printf("G->n==%d\n", G->n);
	printf("β����\tβ����\n");
	for (int i = 0; i < G->n; i++) {
		printf("%d\t", i);
		for (int j = 0; j < G->n; j++) {
			if (G->edges[i][j] == 1)
				printf("%d\t", j);
		}
		printf("\n");
	}
}
void DispAdj(AdjGraph *G) {
	ANode* p;
	printf("β����\tβ����\n");
	for (int i = 0; i < G->n; i++) {
		printf("%d\t", i);
		p = G->adjlist[i].firstarc;
		while (p != NULL) {
			printf("%d\t", p->adjvex);
			p = p->nextarc;
		}
		printf("\n");
	}
}
void BFS(AdjGraph* G,int v) {
	int visted[MAXV] = { 0 };
	ANode* p = NULL;
	queue<int> q;
	q.push(v);
	visted[v] = 1;
	while (!q.empty()) {
		v=q.front();q.pop();
		printf("%2d", v);
		p = G->adjlist[v].firstarc;
		while (p != NULL) {
			if (visted[p->adjvex] == 0) {
				q.push(p->adjvex);
				visted[p->adjvex] = 1;
			}
			p = p->nextarc;
		}
	}
	printf("\n");

}
void DFSNoRe(AdjGraph* G,int v) {
	stack<int> s;
	ANode* p=NULL;
	int visted[MAXV] = { 0 };
	printf("%2d", v);
	visted[v] = 1;
	s.push(v);
	while (!s.empty()) {
		v = s.top();
		p = G->adjlist[v].firstarc;
		while (p && visted[p->adjvex] == 1) {
			p = p->nextarc;
		}
		if (p == NULL) {
			v = s.top();
			s.pop();
		}
		else {
			v = p->adjvex;
			printf("%2d", v);
			visted[v] = 1;
			s.push(v);
		}
	}
	printf("\n");
}
void DFSRe(AdjGraph* G, int v) {
	ANode* p=NULL;
	Visted[v] = 1;
	printf("%2d", v);
	p = G->adjlist[v].firstarc;
	while (p != NULL) {
		if (Visted[p->adjvex] == 0) {
			DFSRe(G, p->adjvex);
		}
		p = p->nextarc;
	}
}
void PathAll(AdjGraph* G, int u, int v, int path[], int d) {
	int w, i; ANode* p = NULL;
	d++; path[d] = u;
	Visted[u] = 1;
	if (u == v && d >= 0) {
		for (int i = 0; i <= d; i++) {
			printf("%2d", path[i]);
		}
		printf("\n");
	}
	p = G->adjlist[u].firstarc;
	while (p != NULL) {
		w = p->adjvex;
		if (Visted[w] == 0) {
			PathAll(G, w, v, path, d);
		}
		p = p->nextarc;
	}
	Visted[u] = 0;
}
void PathAlli(AdjGraph* G, int u, int v, int path[], int d,int a) {
	int w; ANode* p = NULL;
	d++; path[d] = u;
	Visted[u] = 1;
	if (u == v && d ==a) {
		for (int i = 0; i <= d; i++) {
			printf("%2d", path[i]);
		}
		printf("\n");
	}
	p = G->adjlist[u].firstarc;
	while (p != NULL) {
		w = p->adjvex;
		if (Visted[w] == 0) {
			PathAlli(G, w, v, path, d,a);
		}
		p = p->nextarc;
	}
	Visted[u] = 0;
}
void DestoryMat(MatGraph* G) {
	free(G);
}
void DestoryAdj(AdjGraph* G) {
	ANode* p=NULL,*pre=NULL;
	for (int i = 0; i < G->n; i++) {
		p = G->adjlist[i].firstarc;
		while (p != NULL) {
			pre = p;
			p = p->nextarc;
			free(pre);
		}
	}
	free(G);
}
void menu() {
	system("cls");
	printf("1. ����ͼ���ڽӾ�����ڽӱ����\n");
	printf("2. DFS�ĵݹ鼰�ǵݹ����\n");
	printf("3. BFS����\n");
	printf("4. ����������㳤��Ϊn�ļ�·��\n");
	printf("5. ��������������·��\n");
	printf("6. ��������ͼ\n");
	printf("7. �˳�\n\n");
	printf("�������������");
}