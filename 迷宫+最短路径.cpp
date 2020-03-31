#include<stdio.h>
#include<stdlib.h>
#define MaxSize 405 
#define Max 50
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
    int R, C;
    int count = 1;
    scanf("%d%d", &R, &C);
    getchar();
    char map[Max][Max];
    for (int i = 0; i < C + 2;i++){
        map[0][i] = '#';
        map[R+1][i] = '#';
    }
    for (int i = 1; i < R+1; i++)
    {
        map[i][0] = '#';
        int j = 0;
        for (j = 1; j < C+1; j++)
        {
            scanf("%c", &map[i][j]);
        }
        getchar();
        map[i][j] = '#';
    }
    {
        for (int i = 0; i < R + 2;i++){
            for (int j = 0; j < C + 2;j++){
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
    }
    int d[4][2] = {{1, 0},{0, 1},{-1, 0},{0, -1}};
    Box exit = {R, C, -1};
    Box e;
    e.i = 1, e.j = 1, e.next = -1;
    Push(L, e);
    map[1][1] = '#';
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
            printf("\n最短路径为：%d", count);
            break;
        }
        while(++e.next<4&&map[e.i+d[e.next][0]][e.j+d[e.next][1]]=='#'){}
        //printf("%d,%d\n", e.i+d[e.next][0],e.j+d[e.next][1]);
        if(e.next<4&&map[e.i+d[e.next][0]][e.j+d[e.next][1]]=='.'){
            L->data[L->top].next = e.next;
            e.i += d[e.next][0];
            e.j += d[e.next][1];
            e.next = -1;
            Push(L, e);
            map[e.i][e.j] = '#';
            count++;
        }else{
            Pop(L, e);
            map[e.i][e.j] = '.';
            count--;
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