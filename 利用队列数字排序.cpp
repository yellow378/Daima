#include<iostream>
#define MaxSize 110
using namespace std;
typedef struct queue{
    int data[MaxSize];
    int front;
    int rear;
} Queue, *Queueptr;

int pow(int k){
    int result = 1;
    for (int i = 0; i < k;i++){
        result *= 10;
    }
    return result;
}
void InitQueue(Queueptr &L);
void enQueue(Queueptr &L, int e);
void deQueue(Queueptr &L, int &e);
void step(int num[], int k, int size);
int main()
{
    int size, num[MaxSize];
    int maxstep=0;
   
    cin >> size;
    for (int i = 0; i < size;i++){
        cin >> num[i];
        int t = num[i];
        int a = 0;
        while(t!=0){
            a++;
            t /= 10;
        }
        maxstep = a > maxstep ? a : maxstep;
    }
    for (int k = 0; k < maxstep;k++){
        step(num, k,size);
    }
    for (int i = 0; i < size;i++){
        if(i==0)
            cout << num[i];
        else 
            cout << " " << num[i];
    }
        return 0;
}
void InitQueue(Queueptr &L)
{
    L=(Queueptr)malloc(sizeof(Queue));
    L->front=-1;
    L->rear = -1;
}
void enQueue(Queueptr &L,int e)
{
    if(L->rear==MaxSize-1) return;
    L->rear++;
    L->data[L->rear]=e;
}
void deQueue(Queueptr &L,int &e)
{
    if(L->front==L->rear) return;
    L->front++;
    e=L->data[L->front];
}
void step(int num[],int k,int size)
{
    int value;
    Queueptr d0, d1, d2, d3, d4, d5, d6, d7, d8, d9;
    InitQueue(d0);
    InitQueue(d1);
    InitQueue(d2);
    InitQueue(d3);
    InitQueue(d4);
    InitQueue(d5);
    InitQueue(d6);
    InitQueue(d7);
    InitQueue(d8);
    InitQueue(d9);
    for (int i = 0; i < size;i++){
        value = num[i] / pow(k) % 10;
        switch (value)
        {
        case 0:
            enQueue(d0, num[i]);
            break;
        case 1:
            enQueue(d1, num[i]);
            break;
        case 2:
            enQueue(d2, num[i]);
            break;
        case 3:
            enQueue(d3, num[i]);
            break;
        case 4:
            enQueue(d4, num[i]);
            break;
        case 5:
            enQueue(d5, num[i]);
            break;
        case 6:
            enQueue(d6, num[i]);
            break;
        case 7:
            enQueue(d7, num[i]);
            break;
        case 8:
            enQueue(d8, num[i]);
            break;
        case 9:
            enQueue(d9, num[i]);
            break;
        }
    }
    int i = 0;
    cout << "Step" << k + 1 << "." << endl;
    cout << "Queue0:";
    while(d0->front!=d0->rear){
        deQueue(d0, value);
        if(d0->front==d0->rear)
            cout << value;
        else
            cout << value << " ";
        num[i++] = value;
    }
    cout << endl;
    cout << "Queue1:";
    while(d1->front!=d1->rear){
        deQueue(d1, value);
        if(d1->front==d1->rear)
            cout << value;
        else
            cout << value << " ";
        num[i++] = value;
    }
    cout << endl;
    cout << "Queue2:";
    while(d2->front!=d2->rear){
        deQueue(d2, value);
        if(d2->front==d2->rear)
            cout << value;
        else
            cout << value << " ";
        num[i++] = value;
    }
    cout << endl;
    cout << "Queue3:";
    while(d3->front!=d3->rear){
        deQueue(d3, value);
        if(d3->front==d3->rear)
            cout << value;
        else
            cout << value << " ";
        num[i++] = value;
    }
    cout << endl;
    cout << "Queue4:";
    while(d4->front!=d4->rear){
        deQueue(d4, value);
        if(d4->front==d4->rear)
            cout << value;
        else
            cout << value << " ";
        num[i++] = value;
    }
    cout << endl;
    cout << "Queue5:";
    while(d5->front!=d5->rear){
        deQueue(d5, value);
        if(d5->front==d5->rear)
            cout << value;
        else
            cout << value << " ";
        num[i++] = value;
    }
    cout << endl;
    cout << "Queue6:";
    while(d6->front!=d6->rear){
        deQueue(d6, value);
        if(d6->front==d6->rear)
            cout << value;
        else
            cout << value << " ";
        num[i++] = value;
    }
    cout << endl;
    cout << "Queue7:";
    while(d7->front!=d7->rear){
        deQueue(d7, value);
        if(d7->front==d7->rear)
            cout << value;
        else
            cout << value << " ";
        num[i++] = value;
    }
    cout << endl;
    cout << "Queue8:";
    while(d8->front!=d8->rear){
        deQueue(d8, value);
        if(d8->front==d8->rear)
            cout << value;
        else
            cout << value << " ";
        num[i++] = value;
    }
    cout << endl;
    cout << "Queue9:";
    while(d9->front!=d9->rear){
        deQueue(d9, value);
        if(d9->front==d9->rear)
            cout << value;
        else
            cout << value << " ";
        num[i++] = value;
    }
    cout << endl;
}