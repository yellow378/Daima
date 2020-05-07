//����1913������
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
			printf("���������У�");
			scanf_s("%d%d", &n, &m);
			printf("�������һ������\n");
			CreateTupMatrix(a, n, m);
			printf("������ڶ�������\n");
			CreateTupMatrix(b, n, m);
			break;
		}
		case 2: {
			printf("��һ������\n");
			PrintTupMatrix(a);
			printf("�ڶ�������\n");
			PrintTupMatrix(b);
			system("PAUSE");
			break;
		}
		case 3: {
			TranTupMatrix(a, b, at, bt);
			printf("��һ������ת�ã�\n");
			PrintTupMatrix(at);
			printf("�ڶ�������ת�ã�\n");
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
	t.nums = 0;			//��ʼ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k;
			scanf_s("%d", &k);
			if (k) {					//����Ϊ�㣬������Ԫ��
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
	c.nums = 0;				//��ʼ��
	a.data[a.nums].r = a.data[a.nums].c = -1;	
	b.data[a.nums].r = b.data[a.nums].c = -1;	//�߽��ֹ������±�����Խ�����Ӱ��
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
	at.nums = a.nums;		//��ʼ��
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
	bt.nums = b.nums;		//��ʼ��
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
		printf("���ܽ��г˷�!\n");
		return;
	}
	c.rows = a.rows, c.cols = b.cols,c.nums = 0;	//��ʼ��
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
	printf("1. ��������\n");
	printf("2. ��ӡ��������\n");
	printf("3. ��Ԫ��ת��\n");
	printf("4. ��Ԫ��ӷ�\n");
	printf("5. ��Ԫ��˷�\n");
	printf("6. �˳�\n");
	printf("\n�������������");
}
