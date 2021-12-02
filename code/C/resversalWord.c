#include <stdio.h>
#include <string.h>
#include <windows.h>
int main(){
    char ch;
    char msg[5][10];
    int i = 0,j = 0;
    char end;
    while((ch=getchar())!=EOF){
        if(ch == '.'||ch == '?'){
            msg[i][j]='\0';
            end = ch;
            break;
        }
        else if(ch!=' '){
            msg[i][j++]=ch;
        }
        else{
            //msg[i][j]='\0';
            i++;
            j = 0;
        }
    }
    for(int k = i;k>=0;k--){
        printf("%s",msg[k]);
        if(k!=0)
            printf(" ");
        else
            putchar(end);
    }
    system("pause");
    return 0;
}