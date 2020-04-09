#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef struct box{
    int i;
    int j;
    int next;
} Box;
typedef Box Elemtype;
typedef struct{
    Box data[MaxSize];
    int top;
} Stack, *Stackptr;

void InitStack(Stackptr &L);
bool GetTop(Stackptr L,Elemtype &e);
bool Push(Stackptr &L,Elemtype e);
bool Pop(Stackptr &L,Elemtype &e);
bool StackEmpty(Stackptr L);
bool DestroyStack(Stackptr &L);

int main()
{
    int minlen = MaxSize;
    Stackptr L;
    InitStack(L);
    Box minpath[MaxSize];                               //记录最短路径
    int map[][6] = {
        {1,1,1,1,1,1},
        {1,0,0,0,0,1},
        {1,0,1,0,0,1},
        {1,0,0,0,1,1},
        {1,1,0,0,0,1},
        {1,1,1,1,1,1}};                                 //迷宫的地图
    int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};   //方向
    Box exit = {4,4,-1};                                //迷宫出口
    Box e;
    e.i = 1, e.j = 1, e.next = -1;                      //迷宫入口
    Push(L, e);
    map[1][1] = 1;
    while(!StackEmpty(L)){
        GetTop(L, e);
        if(e.i==exit.i&&e.j==exit.j){                   //找到一个出口

            if(L->top<minlen){
                minlen = L->top;
                for (int i = 0; i <= L->top;i++){
                    minpath[i] = L->data[i];
                }
            }
            printf("其中一条为：\n");                   //判断最小路径
            for (int i = 0; i <= L->top;i++){
                printf("%d,%d\t", L->data[i].i, L->data[i].j);
                if(i!=0&&i%5==0)
                    printf("\n");
            }
            printf("\n");                               //打印当前路径
            Pop(L, e);
            map[e.i][e.j] = 0;                          //把出口出栈
        }
        while(++e.next<4&&map[e.i+d[e.next][0]][e.j+d[e.next][1]]==1){}
        //找到可走的方位j或没有方位可走
        if(e.next<4&&map[e.i+d[e.next][0]][e.j+d[e.next][1]]==0){
            L->data[L->top].next = e.next;
            e.i += d[e.next][0];
            e.j += d[e.next][1];
            e.next = -1;
            Push(L, e);
            map[e.i][e.j] = 1;                          //入栈方向
        }else{
            Pop(L, e);
            map[e.i][e.j] = 0;                          //若没有方位可走，出栈当前Box
        }
    }

    printf("最短路径：\n");
    for (int i = 0; i <= minlen;i++){
        printf("%d,%d\t", minpath[i].i, minpath[i].j);
        if(i!=0&&(i)%5==0)
            printf("\n");
    }
    printf("\n");
    printf("最短路径的长度为：%d\n", minlen+1);

    DestroyStack(L);
    return 0;
}
void InitStack(Stackptr &L)
{
    L=(Stackptr)malloc(sizeof(Stack));
    L->top=-1;
}
bool GetTop(Stackptr L,Elemtype &e)
{
    if(L->top==-1) return false;
    else e=L->data[L->top];
    return true;
}
bool Push(Stackptr &L,Elemtype e)
{
    if(L->top==MaxSize-1) return false;
    L->data[++L->top]=e;
    return true;
}
bool Pop(Stackptr &L,Elemtype &e)
{
    if(L->top==-1) return false;
    e=L->data[L->top--];
    return true;
}
bool StackEmpty(Stackptr L)
{
    return (L->top==-1);
}
bool DestroyStack(Stackptr &L){
    free(L);
    return true;
}