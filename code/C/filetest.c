#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    FILE *fp;
    char ch;
    int num = 0;
    if((fp = fopen("C\\text","rw"))==NULL){
        printf("open file faile\n");
        system("pause");
        return 0;
    }
    while((ch = getc(fp))!=EOF){
        putchar(toupper(ch));
        num++;
    }
    printf("num = %d",num);
    fclose(fp);
    system("pause");
    return 0;

}