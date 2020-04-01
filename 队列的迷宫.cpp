#include<stdio.h>
#include<stdlib.h>
#define MaxSize 300
#define Max 20
typedef struct box{
    int i;
    int j;
    int pre;
} Box;
typedef Box Elemtype;
typedef struct{
    Box data[MaxSize];
    int front;
    int rear;
} Queue, *Queueptr;

void InitQueue(Queueptr &L);
bool enQueue(Queueptr L,Elemtype e);
bool deQueue(Queueptr L,Elemtype &e);
bool QueueEmpty(Queueptr L);
void print(Queueptr L, int front);

int main()
{
    Queueptr L;
    InitQueue(L);
    Box path[MaxSize];
    int R, C;
    scanf("%d%d", &R, &C);
    getchar();
    char map[Max][Max];
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf("%c ", &map[i][j]);
        }
    }
    Box exit,in;
    scanf("%d%d",&in.i,&in.j);
    scanf("%d%d",&exit.i,&exit.j);
    int d[4][2] = {{-1,0},{0, 1},{1, 0},{0, -1}};
    Box e;
    e.i = in.i, e.j = in.j ,e.pre= -1;
    enQueue(L, e);
    map[e.i][e.j] = '1';
    int i, j, pre;
    int flag = 0;
    while(!QueueEmpty(L)){
        deQueue(L, e);
        i = e.i, j = e.j;
        if(i==exit.i&&j==exit.j){
            print(L, L->front);
            flag = 1;
            break;
        }
        for (int dc = 0; dc < 4;dc++){
            if(map[i+d[dc][0]][j+d[dc][1]]=='0'){
                e.i = i + d[dc][0];
                e.j = j + d[dc][1];
                e.pre = L->front;
                enQueue(L, e);
                map[i + d[dc][0]][j + d[dc][1]] = '1';
            }
        }
    }
    if(flag==0){
        printf("-1");
    }

    return 0;
}
void InitQueue(Queueptr &L)
{
    L=(Queueptr)malloc(sizeof(Queue));
    L->front = L->rear = -1;
}
bool enQueue(Queueptr L,Elemtype e)
{
    if(L->rear==MaxSize-1) return false;
    L->rear++;
    L->data[L->rear] = e;
    return true;
}
bool deQueue(Queueptr L,Elemtype &e)
{
    if(L->front==L->rear) return false;
    e=L->data[++L->front];
    return true;
}
bool QueueEmpty(Queueptr L)
{
	if(L->front==L->rear) return true;
	else return false;
}
void print(Queueptr L,int front){
    int k = front, j, ns = 0;
    do{
        j = k;
        k = L->data[k].pre;
        L->data[j].pre = -1;
    } while (k != 0);
    k = 0;
    while(k<MaxSize){
        if(L->data[k].pre==-1){
            ns++;
            printf("(%d,%d)", L->data[k].i, L->data[k].j);
            if(ns%5==0)
                printf("\n");
        }
        k++;
    }
}
