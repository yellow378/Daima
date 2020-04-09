#include<stdio.h>
#include<string.h>
#define MaxSize 100
void GetNext(char *exp,int next[]) 
{
    next[0] = -1;
    int j = 0, k = -1;
    int n = strlen(exp);
    while(j<n){
        if(k==-1||exp[k]==exp[j]){
            j++;
            k++;
            next[j] = k;
        }else{
            k = next[k];
        }
    }
}
int Find(char *exp,char *ob,int next[]){
    int i = 0, j = 0;
    int n = strlen(exp);
    int m = strlen(ob);
    while(i<n){
        while(j<m){
            if(exp[i]!=ob[j]){
                switch(next[j]){
                    case -1:
                        i++;
                        j = 0;
                        break;
                    default:
                        j = next[j];
                }
            }else{
                i++;
                j++;
            }
        }
        if(j==m)
            return i-m;
    }
    return false;
}
int KMP(char *exp,char *ob,int next[]){
    int n = strlen(exp);
    int m = strlen(ob);
    int i = 0, j = 0;
    while(i<n&&j<m){
        if(j==-1||exp[i]==ob[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j==m)
        return i - m;
    else
        return -1;
}
int main()
{
    char exp[MaxSize];
    scanf("%s", exp);
    char ob[MaxSize];
    scanf("%s", ob);
    int next[MaxSize];
    int n = strlen(exp);
    GetNext(exp, next);
    int result = Find(exp, ob, next);
    int result2 = KMP(exp, ob, next);
    for(int i=0;i<n;i++){
    	printf("%d ",next[i]);
	} 
	printf("\n");
    printf("%d,%d", result,result2);
    return 0;
}
