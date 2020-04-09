#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef char Elemtype;
typedef struct {
    Elemtype data[MaxSize];
    int front;
    int rear;
} SqQueue, *Queueptr;

bool InitSqQueue(Queueptr &L);
bool enSqQueue(Queueptr &L, Elemtype e);
bool deSqQueue(Queueptr &L, Elemtype &e);
bool SqQueueEmpty(Queueptr L);
bool DestoryQueue(Queueptr &L);
int main()
{
    Elemtype e;
    Queueptr q;
    InitSqQueue(q);
    int n = SqQueueEmpty(q);
    if(n==1){
        printf("yes\n");
    }else{
        printf("no\n");
    }
    enSqQueue(q, 'a');
    enSqQueue(q, 'b');
    enSqQueue(q, 'c');
    enSqQueue(q, 'd');
    deSqQueue(q, e);
    printf("%c\n", e);
    enSqQueue(q, 'e');
    enSqQueue(q, 'f');
    enSqQueue(q, 'g');
    while(!SqQueueEmpty(q)) {
        deSqQueue(q, e);
        printf("%c ", e);
    }
    printf("\n");
    DestoryQueue(q);
    return 0;
}
bool InitSqQueue(Queueptr &L){
    L = (Queueptr)malloc(sizeof(SqQueue));
    L->front = L->rear = 0;
    return true;
}
bool enSqQueue(Queueptr &L, Elemtype e){
    if((L->rear+1)%MaxSize==L->front)
        return false;
    L->rear = (L->rear + 1) % MaxSize;
    L->data[L->rear] = e;
    return true;
}
bool deSqQueue(Queueptr &L, Elemtype &e){
    if(L->rear==L->front)
        return false;
    L->front = (L->front + 1) % MaxSize;
    e = L->data[L->front];
    return true;
}
bool SqQueueEmpty(Queueptr L){
    return L->front == L -> rear;
    return true;
}
bool DestoryQueue(Queueptr &L){
    free(L);
    return true;
}