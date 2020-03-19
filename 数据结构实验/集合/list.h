//¼ÆËã1913ÀîÎÄÐù 
#include<iostream>
#include<cstdlib> 
#define MaxSize 100
using namespace std;
typedef struct List{
    int data[MaxSize];
    int len;
} List, *Listptr;
void Creatlist(Listptr &L);
bool cheaklist(Listptr L);
void showall(Listptr L);
void showmenu();
void add(Listptr LA,Listptr LB,Listptr &LC);
void sub(Listptr LA,Listptr LB,Listptr &LC);
void mul(Listptr LA,Listptr LB,Listptr &LC);
