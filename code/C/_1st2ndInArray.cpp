#include <stdio.h>
#include <windows.h>
void find_two_largest(int a[],int n,int* first1,int *second){
    if(n <= 0){
        *first1 = 0;
        *second = 0; 
    }
    else if(n == 1){
        *first1 = *second = a[0];
    }
    else{
        if(a[0]>a[1]){
            *first1 = a[0];
            *second = a[1];
        }
        else{
            *first1 = a[1];
            *second = a[0];
        }
        for(int i = 2;i<n;i++){
            if (a[i] > *first1) {
                *second = *first1;
                *first1 = a[i];
            } else if (a[i] > *second)
                *second = a[i];
        }
    }
}
int main(){
    int a[5] = {5,4,2,1,3};
    int second,first1;//定义成指针报错了哦
    find_two_largest(a,5,&first1,&second);
    printf("first1 is %d.\nsecond is %d.\n",first1,second);
    system("pause");
    return 0;
}