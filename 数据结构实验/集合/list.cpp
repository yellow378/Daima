#include"list.h"
//����1913������ 
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
    cout << "�����뼯�ϴ�С��";
	int n;
	cin >> n;
	L->len = n;
    do{
		
	    cout << "�����缯��Ԫ�أ�";
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
    printf("1.��������A\n");
	printf("2.��������B\n");
	printf("3.��ӡ����A��Ԫ��\n");
	printf("4.��ӡ����B��Ԫ��\n");
	printf("5.��A,B�Ĳ���\n");
	printf("6.��A,B�Ĳ\n");
	printf("7.��A,B�Ľ���\n");
	printf("8.�˳�\n\n");
	printf("���������������:");
}
void add(Listptr LA,Listptr LB,Listptr &LC){//�󽻼�
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
void sub(Listptr LA,Listptr LB,Listptr &LC){//�� 
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
void mul(Listptr LA,Listptr LB,Listptr &LC)//�󲢼� 
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
