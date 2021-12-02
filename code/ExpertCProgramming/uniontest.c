#include <stdio.h>
#include <windows.h>

union{
    double d;
    float f;
} u;

int main(){
    u.d = 10.0;
    printf("float f = %f\n",u.f);
    u.f = 10.0;
    printf("double d = %f\n",u.d);
    system("pause");
}