//计算1913李文轩 
#include"list.h" 
int main()
{
    Listptr L1 = NULL, L2 = NULL, L3 = NULL;
    int n;
    InitList(L1);
    InitList(L2);
    while(1){
        menu();
        scanf("%d", &n);
        switch(n){
            case 1:{
                CreatList(L1);
                break;
            } 
            case 2:{
                CreatList(L2);
                break;
            }
            case 3:{
                showList(L1);
                break;
            } 
            case 4:{
                showList(L2);
                break;
            } 
            case 5:{
                addList(L1,L2,L3);
                showList(L3);
                break;
            } 
            case 6:{
                mulList(L1, L2, L3);
                showList(L3);
                break;
            } 
            case 7:{
               exit(0);
               break;
            } 
        }
    }
    return 0;
}
//计算1913李文轩
void InitList(Listptr &L)
{
    L = (Listptr)malloc(sizeof(List));
    L->pow = -1;
    L->next = NULL;
}
//计算1913李文轩
void CreatList(Listptr &L)
{
    Listptr t = L,r;
    int n, d, p;
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        scanf("%d%d", &d, &p);
        r = (Listptr)malloc(sizeof(List));
        r->data = d;
        r->pow = p;
        t = L;
        while(t->next&&r->pow<t->next->pow)
            t = t->next;
        r->next = t->next;
        t->next = r;
    }
}
//计算1913李文轩
void showList(Listptr L)
{
    Listptr t = L->next;
    printf("f(x) = ");
    while(t)
    {
        if(t==L->next){
            if(t->data==1){
            }else if(t->data==-1){
                printf("-");
            }else
                printf("%d", t->data);
            if(t->pow==1){
                printf("x");
            }else if(t->pow==0){
            }else{
                printf("x^%d", t->pow);
            }
        }
        else{
            if(t->data<0){
                if(t->data!=-1)
                    printf("%d", t->data);
                else{
                    printf("-");
                }
                if(t->pow==1){
                    printf("x");
                }else if(t->pow==0){
                }else{
                    printf("x^%d", t->pow);
                }
            }
            else{
                printf("+");
                if(t->data!=1)
                    printf("%d", t->data);
                if(t->pow==1){
                    printf("x");
                }else if(t->pow==0){
                }else{
                    printf("x^%d", t->pow);
                }
            }
        }
        t = t->next;
    }
    printf("\n");
    system("PAUSE");
}
//计算1913李文轩
void addList(Listptr L1,Listptr L2,Listptr &L3)
{
    L3 = (Listptr)malloc(sizeof(List));
    L3->next = NULL;
    Listptr t1, t2, t3,r;
    t1 = L1->next;
    t2 = L2->next;
    t3 = L3;
    while(t1&&t2){
        if(t1->pow>t2->pow){
            r = (Listptr)malloc(sizeof(List));
            r->data = t1->data;
            r->pow = t1->pow;
            r->next = t3->next;
            t3->next = r;
            t3 = t3->next;
            t1 = t1->next;
        }else if(t1->pow<t2->pow){
            r = (Listptr)malloc(sizeof(List));
            r->data = t2->data;
            r->pow = t2->pow;
            r->next = t3->next;
            t3->next = r;
            t3 = t3->next;
            t2 = t2->next;
        }else{
            r = (Listptr)malloc(sizeof(List));
            r->data = t2->data+t1->data;
            r->pow = t2->pow;
            if(r->data!=0){
                r->next = t3->next;
                t3->next = r;
                t3 = t3->next;
            } 
            t2 = t2->next;
            t1 = t1->next;
        }
    }
//    while(t1){
//            r = (Listptr)malloc(sizeof(List));
//            r->data = t1->data;
//            r->pow = t1->pow;
//            r->next = t3->next;
//            t3->next = r;
//            t3 = t3->next;
//            t1 = t1->next;
//    }
//    while(t2){
//            r = (Listptr)malloc(sizeof(List));
//            r->data = t2->data;
//            r->pow = t2->pow;
//            r->next = t3->next;
//            t3->next = r;
//            t3 = t3->next;
//            t2 = t2->next;
//    }
    
}
//计算1913李文轩
void mulList(Listptr L1,Listptr L2,Listptr &L3)
{
    L3 = (Listptr)malloc(sizeof(List));
    L3->next = NULL;
    Listptr t1, t2, t3,r;
    t1 = L1->next;
    t2 = L2->next;
    t3 = L3;
    while(t1){
        t2 = L2->next;
        while(t2){
            r = (Listptr)malloc(sizeof(List));
            r->data = t1->data * t2->data;
            r->pow = t1->pow + t2->pow;
            t3 = L3;
            while(t3->next&&t3->next->pow>r->pow)
                t3 = t3->next;
            if(t3->next&&t3->next->pow==r->pow){
                t3->next->data += r->data;
                if(t3->next->data==0){
                    Listptr n = t3->next;
                    t3->next = t3->next->next;
                    free(n);
                }
            }else{
                r->next = t3->next;
                t3->next = r;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
}
//计算1913李文轩 
void menu()
{
    system("cls");
    printf("1.输入多项式A\n");
    printf("2.输入多项式B\n");
    printf("3.打印多项式A\n");
    printf("4.打印多项式B\n");
    printf("5.多项式相加\n");
    printf("6.多项式相乘\n");
    printf("7.退出\n\n");
    printf("请输入选项：");
}
