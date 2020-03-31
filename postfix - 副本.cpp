#include<cstdio>
#include<cstdlib>
#include<cmath>
#define MaxSize 1000
using namespace std;
typedef char ElemType;
typedef struct stack{
    ElemType data[MaxSize];
    int top;
}SqStack,*Stackptr;
typedef struct stack1{
    int data[MaxSize];
    int top;
}SqStack1,*Stackptr1;

void InitStack(Stackptr &L);
bool GetTop(Stackptr L,ElemType &e);
bool Push(Stackptr &L,ElemType e);
bool Pop(Stackptr &L,ElemType &e);
bool StackEmpty(Stackptr L);
void InitStack1(Stackptr &L);
bool GetTop1(Stackptr L,int &e);
bool Push1(Stackptr &L,int e);
bool Pop1(Stackptr &L,int &e);
bool StackEmpty1(Stackptr L);
void topost(char *exp,char post[MaxSize]);
int toresult(char *post);
int main()
{
    int n;
    int e;
    scanf("%d",&n);
    getchar();
    char exp[MaxSize];
    char post[MaxSize];
    for(int i=0;i<n;i++){
        gets(exp);
        topost(exp,post);
        printf("%s\n",post);
        e=toresult(post);
        printf("%d\n",e);
    }
    return 0;
}
void InitStack(Stackptr &L)
{
    L=(Stackptr)malloc(sizeof(SqStack));
    L->top=-1;
}
bool GetTop(Stackptr L,ElemType &e)
{
    if(L->top==-1) return false;
    else e=L->data[L->top];
    return true;
}
bool Push(Stackptr &L,ElemType e)
{
    if(L->top==MaxSize-1) return false;
    L->data[++L->top]=e;
    return true;
}
bool Pop(Stackptr &L,ElemType &e)
{
    if(L->top==-1) return false;
    e=L->data[L->top--];
    return true;
}
bool StackEmpty(Stackptr L)
{
    return (L->top==-1);
}
void InitStack1(Stackptr1 &L)
{
    L=(Stackptr1)malloc(sizeof(SqStack1));
    L->top=-1;
}
bool GetTop1(Stackptr1 L,int &e)
{
    if(L->top==-1) return false;
    else e=L->data[L->top];
    return true;
}
bool Push1(Stackptr1 &L,int e)
{
    if(L->top==MaxSize-1) return false;
    L->data[++L->top]=e;
    return true;
}
bool Pop1(Stackptr1 &L,int &e)
{
    if(L->top==-1) return false;
    e=L->data[L->top--];
    return true;
}
bool StackEmpty1(Stackptr1 L)
{
    return (L->top==-1);
}
void topost(char *exp,char post[MaxSize])
{
    Stackptr T=(Stackptr)malloc(sizeof(SqStack));
    InitStack(T);
    int j=0;
    char e;
    while(*exp!='\0')    
    {
        switch(*exp){
            case '(':   Push(T,'(');
                        exp++;
                        break;
            case ')':   Pop(T,e);
                        while(e!='('){
                            post[j++]=e;
                            Pop(T,e);
                        }
                        exp++;
                        break;
            case '-':
            case '+':   while(!StackEmpty(T)){
                            GetTop(T,e);
                            if(e!='('){
                                post[j++]=e;
                                Pop(T,e);
                            }else{
                                break;
                            }
                        }
                        Push(T,*exp);
                        exp++;
                        break;
            case '*':
            case '/':   while(!StackEmpty(T)){
                            GetTop(T,e);
                            if(e=='*'||e=='/'){
                                post[j++]=e;
                                Pop(T,e);
                            }else{
                                break;
                            }
                        }
                        Push(T,*exp);
                        exp++;
                        break;
            default: 	while(*exp<='9'&&*exp>='0'){
                                post[j++]=*exp;
                                exp++;
                            }
                            post[j++]='#';
            
            }
    }        
    while(!StackEmpty(T)){
        Pop(T,e);
        post[j++]=e;
    }
    post[j]='\0';
}
int toresult(char *post)
{
	int a,b,c,d,e;
	Stackptr1 T;
	InitStack1(T);
	while(*post!='\0'){
		switch(*post){
			case '+':
				Pop1(T,a);
				Pop1(T,b);
				c=a+b;
				Push1(T,c);
				break;
			case '-':
				Pop1(T,a);
				Pop1(T,b);
				c=b-a;
				Push1(T,c);
				break;
			case '*':
				Pop1(T,a);
				Pop1(T,b);
				c=a*b;
				Push1(T,c);
				break;
			case '/':
				Pop1(T,a);
				Pop1(T,b);
				c=b/a;
				Push1(T,c);
				break;
			default:
				d=0;
				while(*post<='9'&&*post>='0'){
					d=d*10+(*post)-'0';
					post++;
				}
				Push1(T,d);
				break;
		} 
		post++;
	}
	GetTop1(T,e);
	return e;
}
