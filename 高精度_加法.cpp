//1. 倒叙存放
//2. 字符串数组读取
#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;
const int MAXN = 1e5 + 4;   //最大的位数
int a[MAXN];                
int b[MAXN];                //加数  
int c[MAXN];                //和
int main()
{
    char s1[MAXN], s2[MAXN]; //读出数据

    int jw = 0;               //进位

    cin >> s1 >> s2;
    int len1 = strlen(s1);
    for (int i = 0; i < len1; i++)
    {
        a[i] = s1[len1 - i - 1] - '0';
    }
    int len2 = strlen(s2);
    for (int i = 0; i < len2; i++)
    {
        b[i] = s2[len2 - i - 1] - '0';
    }

    int len = max(len1, len2) + 1; 
    //位数可能多了一位
    for(int i = 0; i < len; i++){
        c[i] = (a[i] + b[i] + jw) % 10;
        jw = (a[i] + b[i]) / 10;
    }

    //删除前导零
    for(int i = len - 1; i >= 0; i--){
        if(c[i] == 0 && len > 1){
            len--;
        }else{
            break;
        }
    }
    
    //倒叙输出
    for(int i = len - 1; i >= 0; i--){
        cout<<c[i];
    }
    cout<<endl;

    return 0;
}