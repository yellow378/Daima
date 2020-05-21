#include<stdio.h>
#include<stdlib.h>
#define INF 32767
#define MaxSize 20
#define N 20
typedef struct HTNode{
	char data;
	double weight;
	int parent;
	int lchild;
	int rchild;
}HTNode;
typedef struct HCode{
	char cd[N];
	int start;
}HCode;
void CreateHT(HTNode ht[],int n0){
	int i,k,lnode,rnode;
	double min1,min2;
	//初始化
	for(int i=0;i<2*n0-1;i++){
		ht[i].parent=ht[i].lchild=ht[i].rchild=-1;
	}
	//给结点赋值
	for(int i=n0;i<=n0*2-2;i++){
		min1=min2=INF;
		lnode=rnode=-1;
		for(k=0;k<=i-1;k++){
			if(ht[k].parent==-1){
				if(ht[k].weight<min1){
					min2=min1;min1=ht[k].weight;
					rnode=lnode;lnode=k;
				}else if(ht[k].weight<min2){
					rnode=k;
					min2=ht[k].weight;
				}
			}
		}
		ht[i].weight=ht[lnode].weight+ht[rnode].weight;
		ht[i].lchild=lnode;
		ht[i].rchild=rnode;
		ht[lnode].parent=ht[rnode].parent=k;
		ht[i].data='#';
	}

}
void Trans(HTNode ht[],int n0){
	for(int i=0;i<2*n0-1;i++){
		printf("%d\t%c\t%f\t%d\t%d\t%d\n",i,ht[i].data,ht[i].weight,ht[i].parent,ht[i].lchild,ht[i].rchild);
	}
}
void CreateHCode(HTNode ht[],HCode hcd[],int n0){
	int i,f,c;
	HCode hc;
	for(i=0;i<n0;i++){
		hc.start=n0;c=i;
		f=ht[i].parent;
		while(f!=-1){
			if(ht[f].lchild==c)
				hc.cd[hc.start--]='0';
			else
				hc.cd[hc.start--]='1';
			c=f;
			f=ht[f].parent;
		}
		hc.start++;
		hcd[i]=hc;
	}
}
void Show(HTNode ht[],HCode hcd[],int n0){
	for(int i=0;i<n0;i++){
		printf("%c\t",ht[i].data);
		for(int j=hcd[i].start;j<=n0;j++){
			printf("%c",hcd[i].cd[j]);
		}
		printf("\n");
	}
}
int main()
{
    int n0=4;
    HTNode ht[MaxSize];
    ht[0].data='a';
    ht[0].weight=1;
    ht[1].data='b';
    ht[1].weight=7;
    ht[2].data='c';
    ht[2].weight=3;
    ht[3].data='d';
    ht[3].weight=5;

    CreateHT(ht,n0);
    printf("哈夫曼树\n");
    Trans(ht,4);
    HCode hcd[4];
    CreateHCode(ht,hcd,n0);
    printf("哈夫曼编码\n");
    Show(ht,hcd,n0);

}
