#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
#define N 8
#define M 8
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
int Stacklength(Stackptr L);

int main()
{
    Stackptr L;
    InitStack(L);
    Box path[MaxSize];
    int map[N + 2][M + 2] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,1,0,0,0,1,0,1},
        {1,0,0,1,0,0,0,1,0,1},
        {1,0,0,0,0,1,1,0,0,1},
        {1,0,1,1,1,0,0,0,0,1},
        {1,0,0,0,1,0,0,0,0,1},
        {1,0,1,0,0,0,1,0,0,1},
        {1,0,1,1,1,0,1,1,0,1},
        {1,1,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}};
    int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    Box exit = {8, 8, -1};
    Box e;
    e.i = 1, e.j = 1, e.next = -1;
    Push(L, e);
    map[1][1] = 1;
    while(!StackEmpty(L)){
        GetTop(L, e);
        //printf("%d,%d\n", e.i, e.j);
        if(e.i==exit.i&&e.j==exit.j){
            printf("路径如下：\n");
            int i = 0;
            while(!StackEmpty(L)){
                Pop(L, e);
                path[i++] = e;
            }
            int n = i-1;
            for (i = n; i >= 0;i--){
                printf("%d,%d\t", path[i].i, path[i].j);
                if((i+2)%5==0)
                    printf("\n");
            }
        }
        while(++e.next<4&&map[e.i+d[e.next][0]][e.j+d[e.next][1]]==1){}
        //printf("%d,%d\n", e.i+d[e.next][0],e.j+d[e.next][1]);
        if(e.next<4&&map[e.i+d[e.next][0]][e.j+d[e.next][1]]==0){
            L->data[L->top].next = e.next;
            e.i += d[e.next][0];
            e.j += d[e.next][1];
            e.next = -1;
            Push(L, e);
            map[e.i][e.j] = 1;
        }else{
            Pop(L, e);
            map[e.i][e.j] = 0;
        }
    }
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