//计算1913李文轩
#include"btree.h"
int main()
{
	TreeNode *root;
	TTreeNode *b;
	char pre[MaxSize];
	char in[MaxSize];
	int k;
	while(1){
		menu();
		scanf("%d",&k);
		switch(k){
			case 1:{
				CreateTree(root);
				system("PAUSE");
				break;
			}
			case 2:{
				int h=GetHigh(root);
				printf("\n");
				PreShow(root,h,h);
				system("PAUSE");
				break;
			}
			case 3:{
				char c;
				printf("打印谁的左右孩子:");
				getchar();
				scanf("%c",&c);
				Findchild(root,c);
				system("PAUSE");
				break;
			}
			case 4:{
				int h=GetHigh(root);
				printf("high = %d\n",h);
				system("PAUSE");
				break;
			}
			case 5:{
				DestoryTree(root);
				system("PAUSE");
				break;
			}
			case 6:{
				printf("preOrder:");
				scanf("%s",pre);
				printf("inOrder:");
				scanf("%s",in);
				int n=strlen(pre);
				//printf("n=%d\n",n);
				CreateTree_pre_in(b,pre,in,n);
				ShowTree(b);
				printf("\n");
				system("PAUSE");
				break;
			}
			case 7:{
				b=CreateThread(b);
				system("PAUSE");
				break;
			}
			case 8:{
				ThInOrderNoRe(b);
				system("PAUSE");
				break;
			}
			case 9:{
				ThInOrderRe(b,b->lchild);
				system("PAUSE");
				break;
			}
			case 10:{
				exit(0);
				break;
			}
		}
	}
	return 0;
}

void CreateTree(TreeNode *&root){
	TreeNode *add[MaxSize],*p;
	int top=-1,j=0,k=1;
	root=NULL;
	ElemType input[MaxSize],c;
	scanf("%s",input);
	while((c=input[j])!='\0'){
		switch(c){
			case '(':top++;add[top]=p;k=1;break;
			case ')':top--;break;
			case ',':k=2;break;
			default:{
				p=(TreeNode*)malloc(sizeof(TreeNode));
				p->data=c;
				p->lchild=p->rchild=NULL;
				if(root==NULL) root=p;
				else{
					switch(k){
						case 1:add[top]->lchild=p;break;
						case 2:add[top]->rchild=p;break;
					}
				}
				break;
			}
		}
		j++;
	}


}
void PreOrder(TreeNode *root){
	if(root){
		printf("%c",root->data);
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}
int GetHigh(TreeNode *root){
	if(root==NULL) return 0;
	int l,r;
	l=GetHigh(root->lchild);
	r=GetHigh(root->rchild);
	return l>r?l+1:r+1;
}
void PreShow(TreeNode *root,int h,int n){
	if(root){	
		for(int i=0;i<n-h;i++) printf(" ");
		printf("%c",root->data);
		for(int i=0;i<h;i++) printf("*");
		//for(int i=0;i<h;i++) printf("%c",22);
		printf("\n");
		PreShow(root->lchild,h-1,n);
		PreShow(root->rchild,h-1,n);
	}
}
int Findchild(TreeNode *root,ElemType c){
	if(root==NULL){
		return 0;
	}else if(root->data==c){
		if(root->lchild!=NULL){
			printf("lchild: %c\n",root->lchild->data);
		}else{
			printf("lchild: NULL\n");
		}
		if(root->rchild!=NULL){
			printf("rchild: %c\n",root->rchild->data);
		}else{
			printf("rchild: NULL\n");
		}
		return 1;
	}else{
		int status = Findchild(root->lchild,c);
		if(status==0){
			status = Findchild(root->rchild,c);
		}
		return status;
	}
}
void DestoryTree(TreeNode *&root){
	if(root){
		DestoryTree(root->lchild);
		DestoryTree(root->rchild);
		free(root);
	}
}
void inOrder(TreeNode *root){
	if(root){
		inOrder(root->lchild);
		printf("%c",root->data);
		inOrder(root->rchild);
	}
}



//以下函数与线索二叉树有关
void CreateTree_pre_in(TTreeNode *&b,char *pre,char *in,int n){
	if(n<1){
		b=NULL;
	}else{
		b=(TTreeNode*)malloc(sizeof(TTreeNode));
		b->data=*pre;
		int i;
		for(i=0;i<n;i++){
			if(in[i]==*pre)
				break;
		}
		CreateTree_pre_in(b->lchild,pre+1,in,i);
		CreateTree_pre_in(b->rchild,pre+i+1,in+i+1,n-i-1);
	}
}
void ShowTree(TTreeNode *b){
	if(b){
		printf("%c",b->data);
		if(b->lchild||b->rchild){
			printf("(");
			ShowTree(b->lchild);
			if(b->rchild){
				printf(",");
				ShowTree(b->rchild);
				printf(")");
			}
		}
	}
}
void Thread(TTreeNode *&b){
	if(b){
		Thread(b->lchild);
		if(b->lchild==NULL){
			b->lchild=pre;
			b->ltag=1;
		}else{
			b->ltag=0;
		}
		if(pre->rchild==NULL){
			pre->rchild=b;
			pre->rtag=1;
		}else{
			pre->rtag=0;
		}
		pre=b;
		Thread(b->rchild);
	}
}
TTreeNode* CreateThread(TTreeNode *&b){
	TTreeNode *root;
	root=(TTreeNode *)malloc(sizeof(TTreeNode));
	root->rchild=b;
	root->ltag=0,root->rtag=1;
	if(b==NULL){
		root->lchild=root;
	}else{
		root->lchild=b;
		pre=root;
		Thread(b);
		pre->rchild=root;
		pre->rtag=1;
		root->rchild=pre;
	}
	return root;
}
void ThInOrderNoRe(TTreeNode *root){
	TTreeNode *p=root->lchild;
	while(p!=root){
		while(p->ltag==0) p=p->lchild;
		printf("%c",p->data);
		while(p->rtag==1&&p->rchild!=root){
			p=p->rchild;
			printf("%c",p->data);
		}
		p=p->rchild;
	}
}
void ThInOrderRe(TTreeNode* root,TTreeNode *b) {
	if (root == b) return;
	if(b->ltag==0)
		ThInOrderRe(root,b->lchild);
	printf("%c",b->data);
	if(b->rtag==0)
		ThInOrderRe(root,b->rchild);
}
void menu(){
	system("cls");
	printf("1. 由括号表示法创建二叉树\n");
	printf("2. 凹入法输出二叉树\n");
	printf("3. 输出左右孩子结点\n");
	printf("4. 输出二叉树高度\n");
	printf("5. 释放二叉树\n");
	printf("6. 利用前序遍历和中序遍历创建二叉树并打印\n");
	printf("7. 中序线索化二叉树\n");
	printf("8. 非递归输出中序线索二叉树\n");
	printf("9. 递归输出中序线索二叉树\n");
	printf("10. 退出\n\n");

	printf("请输入操作数:");

}