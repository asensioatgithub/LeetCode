#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<set>
using namespace std;

set<string> setOfLCS;      // set保存所有的LCS 

int lcs(char *str1, char *str2){
    // int result = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    // cout<<len1<<endl;
    int **array = NULL;
    array = (int**)malloc(sizeof(int*)*(len1+1));
    for(int i=0;i<len2;i++){
        array[i] = (int*)malloc(sizeof(int)*(len2+1));
    }
    for(int i = 0; i<len1;i++)
        array[i][0] = 0;
    for(int j = 0; j<len2;j++)
        array[0][j] = 0; 
    array[0][0] = 0;
    cout<<array[0][0]<<endl;
    // return array[len1-1][len2-1];

    //  
}

// void PrintLCS(int c[][7], char *x, int i, int j) {         //非递归版PrintLCS
//     static char s[7];
//     int a=i,b=j;
//     int k=c[i][j];
//     s[k]='\0';
//     while(k>0){
//         if(c[i][j]==c[i-1][j]) i--;
//         else if(c[i][j]==c[i][j-1]) j--;
//         else{
//             s[--k]=x[i-1];
//             i--;
//             j--;
//         }
//     }
//     printf("%s\n",s);
//     k = c[a][b];
//     while(k>0){
//         if(c[a][b]==c[a][b-1]) b--;
//         else if(c[a][b]==c[a-1][b]) a--;
//         else{
//             s[--k]=x[a-1];
//             a--;
//             b--;
//         }
//     }
//     printf("%s\n",s);
// } 


void traceBack(int c[][7], string str,char *x, char *y, int i, int j)  
{  
    while (i>0 && j>0)  
    {  
        if (x[i-1] == y[j-1])  
        {  
            str.push_back(x[i-1]);  
            --i;  
            --j;  
        }  
        else  
        {  
            if (c[i-1][j] > c[i][j-1])  
                --i;  
            else if (c[i-1][j] < c[i][j-1])  
                --j;  
            else   // 相等的情况  
            {  
                traceBack(c,str,x,y,i-1,j);  
                traceBack(c,str,x,y,i,j-1);  
                return;  
            }  
        }  
    }  
    
    // cout<<str<<endl;
    setOfLCS.insert(str);

}  


int main(){
    char* str1 = "ABCBDAB";
    char* str2 = "BDCABA";
    //申请一个7行6列的整型数组    
    int (*a)[7]=(int(*)[7])malloc(sizeof(int)*8*7); 
    for (int i = 0; i <= 7; i++) {  
        for( int j = 0; j <= 6; j++) {  
            if(i == 0 || j == 0) {  
                a[i][j] = 0;  
            } else if (str1[i-1] == str2[j-1]) {  
                a[i][j] = a[i-1][j-1] + 1;  
            } else {  
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);  
            }  
        }  
    }  
    cout<<a[7][6]<<endl;
    // PrintLCS(a,str1,7,6);
    string str = "";
    traceBack(a,str,str1,str2,7,6);
    set<string>::iterator beg = setOfLCS.begin();  
    for( ; beg!=setOfLCS.end(); ++beg)  
        cout << *beg << endl;
    getchar();

}