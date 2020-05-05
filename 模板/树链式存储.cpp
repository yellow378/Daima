#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100

typedef char ElemType;
typedef struct node {
	ElemType data;
	struct node* lchild;
	struct node* rchild;
}BTNode;

void CreateBTree(BTNode*& b, char* str);	//创建二叉树
void DestroyBTree(BTNode*& b);				//销毁二叉树
BTNode* FindNode(BTNode* b, ElemType x);	//查找结点

int main()
{
	BTNode* b,*t;
	char str[] = "A(B(C,D),E(F,G))";
	CreateBTree(b, str);
	printf("%c", (t=FindNode(b, 'G'))==NULL?'0':t->data);

	
	DestroyBTree(b);
		
	return 0;
}
void CreateBTree(BTNode*& b, char* str)
{
	b = NULL;
	int j = 0, k = 1;
	BTNode* St[MaxSize], *p;
	int top = -1;
	char ch=str[j];
	while (ch != '\0') {
		switch (ch) {
		case '(': top++; St[top] = p; k = 1; break;
		case ')': top--; break;
		case ',': k = 2; break;
		default:p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (b == NULL) {
				b = p;
			}
			else {
				switch (k) {
				case 1:St[top]->lchild = p;
				case 2:St[top]->rchild = p;
				}
			}
		}
		j++;
		ch = str[j];
	}
}
void DestroyBTree(BTNode*& b) {
	if (b) {
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}
BTNode* FindNode(BTNode* b, ElemType x) {
	BTNode* p;
	if (b == NULL)	return NULL;
	else if (b->data == x) return b;
	else {
		p = FindNode(b->lchild, x);
		if(p) return p;
		else return FindNode(b->rchild, x);
	}
}