#include <stdio.h>
#include <windows.h>
char ga[] = "asdfghjklzxcvbnmqwertyuiop";

void test1(char ca[10]){
    printf("addr of array param = %#x \n",&ca);
    printf("addr ca[0] = %#x \n",&(ca[0]));
    printf("addr ca[1] = %#x \n",&(ca[1]));
    printf("addr sizeof(ca) = %d \n",sizeof(ca));
    printf("addr sizeof(ca[0]) = %d \n",sizeof(ca[0]));
    printf(" ++ca = %#x \n",++ca);
}

void test2(char *p){
    printf("addr of ptr param = %#x \n",&p);
    printf("addr p[0] = %#x \n",&(p[0]));
    printf("addr p[1] = %#x \n",&(p[1]));
    printf("addr sizeof(p) = %d \n",sizeof(p));
    printf("addr sizeof(p[0]) = %d \n",sizeof(p[0]));
    printf(" ++p = %#x \n",++p);
}

int main(){
    printf("addr of global array = %#x \n",&ga);
    printf("addr ga[0] = %#x \n",&(ga[0]));
    printf("addr ga[1] = %#x \n",&(ga[1]));
    printf("addr sizeof(ga) = %d \n",sizeof(ga));
    printf("addr sizeof(ga[0]) = %d \n",sizeof(ga[0]));

    printf("\n");
    test1(ga);
    printf("\n");
    test2(ga);

    system("pause");
    return 0; 
}