#include"list.h"
//计算1913李文轩 
int main()
{
    int k;
    Listptr LA=NULL, LB=NULL,LC=(Listptr)malloc(sizeof(List));
    while(1){
        system("cls");
        showmenu();
        cin >> k;
        switch(k){
            case 1:{
                Creatlist(LA);break;
            }
            case 2:{
                Creatlist(LB);break;
            }
            case 3:{
                showall(LA);break;
            }
            case 4:{
                showall(LB);break;
            }
            case 5:{
               	add(LA,LB,LC);break;
            }
            case 6:{
                sub(LA,LB,LC);break;
            }
            case 7:{
                mul(LA,LB,LC);break;
        	}
            case 8:{
            	free(LA);
				free(LB);
				free(LC); 
                exit(0);
            }
        }
    }
    return 0;
}
void Creatlist(Listptr &L)
{
    L = (Listptr)malloc(sizeof(List));
    cout << "请输入集合大小：";
	int n;
	cin >> n;
	L->len = n;
    do{
		
	    cout << "请输如集合元素：";
	    for (int i = 0; i < n; i++){
	        cin >> L->data[i];
	    }
	}while(cheaklist(L)==0);
}
bool cheaklist(Listptr L)
{
    for (int i = 0; i < L->len;i++){
        int flag = 0;
        for (int j = i + 1; j < L->len;j++){
            if(L->data[i]==L->data[j]){
                flag = 1;
                break;
            }
        }
        if(flag==1){
            return false;
        }
    }
    return true;
}
void showall(Listptr L)
{
    for (int i = 0; i < L->len;i++ )
    {
        if(i==0)
            cout << L->data[i];
        else
            cout <<" " <<L->data[i];
    }
    cout<<endl;
    system("PAUSE");
}
void showmenu()
{
    printf("1.创建集合A\n");
	printf("2.创建集合B\n");
	printf("3.打印集合A的元素\n");
	printf("4.打印集合B的元素\n");
	printf("5.求A,B的并集\n");
	printf("6.求A,B的差集\n");
	printf("7.求A,B的交集\n");
	printf("8.退出\n\n");
	printf("请输入操作的数字:");
}
void add(Listptr LA,Listptr LB,Listptr &LC){//求交集
	int num = 0; 
	for(int i = 0; i != LA->len; i++){
		for(int j = 0;j != LB->len;j++){
			if(LA->data[i] == LB->data[j]){
				LC->data[num++] = LA->data[i];
			}
		}
	}
	LC->len = num;
	showall(LC);
}
void sub(Listptr LA,Listptr LB,Listptr &LC){//求差集 
	LC->len = 0;
	for(int i = 0; i != LA->len; i ++){
		int flag = 0;
		for(int j = 0; j != LB->len; j ++){
			if(LA->data[i] == LB->data[j]){
				flag = 1;
				break;
			}
		}
		if(flag == 0) LC->data[LC->len++] = LC->data[i]; 
	}
	showall(LC);
}
void mul(Listptr LA,Listptr LB,Listptr &LC)//求并集 
{
	LC->len = 0;
	int num = LA->len,k=0;
	for(k = 0;k<num;k++){
		LC->data[LC->len++] = LA->data[k];
	}
	k = 0;
	num = LB->len;
	while(k!=num){
		int flag = 0;
		for(int i=0;i!=LC->len;i++){
			if(LC->data[i] == LB->data[k]){
				flag = 1;
				break;
			} 
		}
		if(flag == 0) LC->data[LC->len++] = LB->data[k];
		k++;
	}
	showall(LC);
}
