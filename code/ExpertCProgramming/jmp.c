#include <setjmp.h>
#include <stdio.h>
#include <windows.h>
jmp_buf buf;
void fun(){
    printf("in fun\n");
    longjmp(buf,1);//返回buf记录的位置
    printf("out fun\n");//不会执行
}
//常用于异常处理，C++中可以对应的catch throw 

int main(){
    if(setjmp(buf)){//记录buf所在位置，必须先调用
        printf("back in main\n");
    }
    else{
        printf("main first\n");
        fun();
        }
    system("pause");
    return 0;
}
