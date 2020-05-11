#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;
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
void PreTrans(BTNode *b);					//递归前序遍历
void InTrans(BTNode *b);					//递归中序遍历
void PosTrans(BTNode *b);					//递归后序遍历
void NoRePreTrans(BTNode *b);				//非递归前序遍历
void NoReInTrans(BTNode *b);				//非递归中序遍历
void NoRePosTrans(BTNode *b);				//非递归后序遍历
void CengXuTrans(BTNode *b);				//层序遍历
int function(BTNode *b);

int main()
{
	BTNode* b,*t;
	char str[] = "A(B(C(D(E))))";
	CreateBTree(b, str);
	//printf("%c", (t=FindNode(b, 'G'))==NULL?'0':t->data);
	printf("递归前序遍历");
	PreTrans(b);
	printf("\n");
	printf("递归中序遍历");
	InTrans(b);
	printf("\n");
	printf("递归后序遍历");
	PosTrans(b);
	printf("\n");
	
	printf("非递归前序遍历");
	NoRePreTrans(b);
	printf("\n");
	printf("非递归中序遍历");
	NoReInTrans(b);
	printf("\n");
	printf("非递归后序遍历");
	NoRePosTrans(b);
	printf("\n");
	printf("层序遍历");
	CengXuTrans(b);
	printf("\n");
	
	
	printf("单节点的数量：%d\n",function(b));
	

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
				case 1:St[top]->lchild = p;break;
				case 2:St[top]->rchild = p;break;
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
void PreTrans(BTNode *b){
	if(b){
		printf("%c",b->data);
		PreTrans(b->lchild);
		PreTrans(b->rchild);
	}
}
void InTrans(BTNode *b){
	if(b){
		InTrans(b->lchild);
		printf("%c",b->data);
		InTrans(b->rchild);
	}
}
void PosTrans(BTNode *b){
	if(b){
		PosTrans(b->lchild);
		PosTrans(b->rchild);
		printf("%c",b->data);
	}
}
void NoRePreTrans(BTNode *b){
	stack<BTNode *> s;
	while(b||!s.empty()){
		while(b){
			s.push(b);
			printf("%c",b->data);
			b=b->lchild;
		}
		if(!s.empty()){
			b=s.top()->rchild;
			s.pop();
		}
	}
}
void NoReInTrans(BTNode *b){
	stack<BTNode *> s;
	while(b||!s.empty()){
		while(b){
			s.push(b);
			b=b->lchild;
		}
		if(!s.empty()){
			b=s.top();
			printf("%c",b->data);
			b=b->rchild;
			s.pop();
		}
	}
}
void NoRePosTrans(BTNode *b){
	BTNode *p,*r;
	int flag;
	stack<BTNode*> q;
	p=b;
	do{
		while(p!=NULL){
			q.push(p);
			p=p->lchild;
		}
		r=NULL;
		flag=1;
		while(!q.empty()&&flag){
			p=q.top();
			if(p->rchild==r){
				printf("%c",p->data);
				q.pop();
				r=p;
			}else{
				p=p->rchild;
				flag=0;
			}
		}
	}while(!q.empty());
}
void CengXuTrans(BTNode *b){
	queue<BTNode*> q;
	BTNode *t;
	q.push(b);
	while(!q.empty()){
		t=q.front();
		q.pop();
		printf("%c",t->data);
		if(t->lchild) q.push(t->lchild);
		if(t->rchild) q.push(t->rchild);
	}
}
int function(BTNode *b){
	if(b==NULL) return 0;
	else if((b->lchild&&b->rchild==NULL)||(b->lchild==NULL&&b->rchild)){
		return 1+function(b->lchild)+function(b->rchild);
	}else{
		return function(b->lchild)+function(b->rchild);
	}
}