//计算1913李文轩
#include "Tuples.h"
int main()
{
	TupMatrix a, b,c;
	TupMatrix at, bt;
	int k;
	while (1) {
		menu();
		scanf_s("%d", &k);
		switch (k) {
		case 1: {
			int n, m;
			printf("请输入行列：");
			scanf_s("%d%d", &n, &m);
			printf("请输入第一个矩阵：\n");
			CreateTupMatrix(a, n, m);
			printf("请输入第二个矩阵：\n");
			CreateTupMatrix(b, n, m);
			break;
		}
		case 2: {
			printf("第一个矩阵：\n");
			PrintTupMatrix(a);
			printf("第二个矩阵：\n");
			PrintTupMatrix(b);
			system("PAUSE");
			break;
		}
		case 3: {
			TranTupMatrix(a, b, at, bt);
			printf("第一个矩阵转置：\n");
			PrintTupMatrix(at);
			printf("第二个矩阵转置：\n");
			PrintTupMatrix(bt);
			system("PAUSE");
			break;
		}
		case 4: {
			AddTupMatrix(a, b, c); PrintTupMatrix(c); 
			system("PAUSE");
			break;
		}
		case 5: {
			MultTupMatrix(a, b, c);
			PrintTupMatrix(c);
			system("PAUSE");
			break;
		}
		case 6: exit(0);
		}
	}
	return 0;
}

void CreateTupMatrix(TupMatrix& t, int n, int m) {
	t.rows = n;
	t.cols = m;
	t.nums = 0;			//初始化
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k;
			scanf_s("%d", &k);
			if (k) {					//若不为零，存入三元组
				ThreeTup p;
				p.r = i, p.c = j, p.data = k;
				t.data[t.nums++] = p;
			}
		}
	}
}
void PrintTupMatrix(TupMatrix t) {
	printf("\ti\tj\tdata\n");
	for (int i = 0; i < t.nums; i++) {
		printf("\t%d\t%d\t%d\n", t.data[i].r, t.data[i].c, t.data[i].data);
	}
}
void AddTupMatrix(TupMatrix a, TupMatrix b, TupMatrix& c) {
	c.cols = a.cols;
	c.rows = a.rows;
	c.nums = 0;				//初始化
	a.data[a.nums].r = a.data[a.nums].c = -1;	
	b.data[a.nums].r = b.data[a.nums].c = -1;	//边界防止数组的下标溢出对结果造成影响
	int numa = 0, numb = 0,numc=0;
	for (int i = 0; i < c.rows; i++) {
		for (int j = 0; j < c.cols; j++) {

			if (a.data[numa].r == i && a.data[numa].c == j) {
				if (b.data[numb].r == i && b.data[numb].c == j) {
					c.data[numc] = a.data[numa++];
					c.data[numc++].data += b.data[numb++].data;
				}
				else {
					c.data[numc++] = a.data[numa++];
				}
			}
			else if (b.data[numb].r == i && b.data[numb].c == j) {
				c.data[numc++] = b.data[numb++];
			}

		}
	}
	c.nums = numc;
}
void TranTupMatrix(TupMatrix a, TupMatrix b, TupMatrix& at, TupMatrix& bt) {
	at.cols = a.rows;
	at.rows = a.cols;
	at.nums = a.nums;		//初始化
	int j = 0;
	for (int v = 0; v < a.cols; v++) {
		for (int k = 0; k < a.nums; k++) {
			if (a.data[k].c == v) {
				at.data[j].r = a.data[k].c;
				at.data[j].c = a.data[k].r;
				at.data[j].data = a.data[k].data;
				j++;
			}
		}
	}

	bt.cols = b.rows;
	bt.rows = b.cols;
	bt.nums = b.nums;		//初始化
	j = 0;
	for (int v = 0; v < b.cols; v++) {
		for (int k = 0; k < b.nums; k++) {
			if (b.data[k].c == v) {
				bt.data[j].r = b.data[k].c;
				bt.data[j].c = b.data[k].r;
				bt.data[j].data = b.data[k].data;
				j++;
			}
		}
	}
}
void MultTupMatrix(TupMatrix a, TupMatrix b, TupMatrix& c) {
	if (a.cols != b.rows) {
		printf("不能进行乘法!\n");
		return;
	}
	c.rows = a.rows, c.cols = b.cols,c.nums = 0;	//初始化
	for (int i = 0; i < c.rows; i++) {
		for (int j = 0; j < c.cols; j++) {
			int result = 0;
			for (int k = 0; k < a.cols; k++) {
				result = result+GetValue(a, i, k) * GetValue(b, k, j);
			}
			if (result) {
				c.data[c.nums].data = result;
				c.data[c.nums].r = i;
				c.data[c.nums++].c = j;
			}
		}
	}
}
int GetValue(TupMatrix a, int i, int j)
{
	for (int k = 0; k < a.nums; k++) {
		if (a.data[k].r == i && a.data[k].c == j) {
			return a.data[k].data;
		}
	}
	return 0;
}
void menu() {
	system("cls");
	printf("1. 创建矩阵\n");
	printf("2. 打印两个矩阵\n");
	printf("3. 三元组转置\n");
	printf("4. 三元组加法\n");
	printf("5. 三元组乘法\n");
	printf("6. 退出\n");
	printf("\n请输入操作数：");
}
