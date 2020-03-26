//¼ÆËã1913ÀîÎÄĞù 
#include<stdio.h>
#include<stdlib.h>
typedef struct list{
    int data;
    int pow;
    struct list *next;
} List, *Listptr;

//3
//-7 1 6 0 3 5
//4
//2 2 7 1 -4 5 2 0
void InitList(Listptr &L);
void CreatList(Listptr &L);
void showList(Listptr L);
void addList(Listptr L1, Listptr L2, Listptr &L3);
void mulList(Listptr L1, Listptr L2, Listptr &L3);
void menu();
