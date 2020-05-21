//¼ÆËã1913ÀîÎÄÐù
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define MaxSize 100

typedef char ElemType;
typedef struct TreeNode{
	ElemType data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;
typedef struct ThreadTreeNode{
	ElemType data;
	int ltag,rtag;
	struct ThreadTreeNode *lchild;
	struct ThreadTreeNode *rchild;
}TTreeNode;
TTreeNode *pre;
void CreateTree(TreeNode *&root);
void PreOrder(TreeNode *root);
void PreShow(TreeNode *root,int h,int n);
int GetHigh(TreeNode *root);
int Findchild(TreeNode *root,ElemType c);
void DestoryTree(TreeNode *&root);
void inOrder(TreeNode *root);
void CreateTree_pre_in(TTreeNode *&b,char *pre,char *in,int n);
void ShowTree(TTreeNode *b);
void Thread(TTreeNode *&b);
TTreeNode* CreateThread(TTreeNode *&b);
void ThInOrderNoRe(TTreeNode* root);
void ThInOrderRe(TTreeNode *root,TTreeNode *b);
void menu();


//A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I)))
//preorder:ABDEHJKLMNCFGI
//inorder:DBJHLKMNEAFCGI