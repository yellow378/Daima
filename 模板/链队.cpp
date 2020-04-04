#include<iostream>
using namespace std;
typedef  char Elemtype;
typedef struct queue{
    Elemtype data;
    struct queue *next;
} node,* nodeptr;
typedef struct {
    nodeptr front;
    nodeptr rear;
} Queue, *Queueptr;
void InitQueue(Queueptr &L);
bool QueueEmpty(Queueptr L);
bool enQueue(Queueptr &L, Elemtype e);
bool deQueue(Queueptr &L, Elemtype &e);
int QueueCount(Queueptr L);
void DestroyQueue(Queueptr &L);
int main(){
    Queueptr L;
    InitQueue(L);
    if(QueueEmpty(L))
        cout << "yes\n";
    else
        cout << "no\n";
    int n;
    Elemtype e;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> e;
        enQueue(L, e);
    }
    deQueue(L, e);
    cout << e << endl;
    cout << QueueCount(L) << endl;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> e;
        enQueue(L, e);
    }
    cout << QueueCount(L) << endl;
    int i = 0;
    while(!QueueEmpty(L)) {
        deQueue(L, e);
        if(i==0) cout<<e;
        else
            cout << " " << e;
        i++;
    }
    DestroyQueue(L);
    return 0;
}
void InitQueue(Queueptr &L){
    L = (Queueptr)malloc(sizeof(Queue));
    L->front = L->rear = NULL;
}
bool QueueEmpty(Queueptr L){
    return (L->rear == NULL);
}
bool enQueue(Queueptr &L, Elemtype e){
    nodeptr t = (nodeptr)malloc(sizeof(node));
    t->data = e;
    t->next = NULL;
    if(L->rear==NULL){
        L->front = t;
        L->rear = t;
    }else{
        L->rear->next = t;
        L->rear = t;
    }
    return true;
}
bool deQueue(Queueptr &L, Elemtype &e)
{
    if(L->rear==NULL)
        return false;
    nodeptr t = L->front;
    if(L->front==L->rear){
    	L->front=L->rear=NULL;
	}else{
		L->front = L->front->next;
	}
    e=t->data;
    free(t);
    return true;
}
int QueueCount(Queueptr L){
	if(L==NULL) return 0; 
    nodeptr t = L->front;
    int count = 0;
    while(t){
        count++;
        t = t->next;
    }
    return count;
}
void DestroyQueue(Queueptr &L)
{
	nodeptr t=L->front;
	nodeptr p;
	if(t!=NULL){
		p=t->next;
		while(p!=NULL){
			free(t);
			t=p;
			p=p->next;
		}
		free(t);
	}
	free(L);
}
