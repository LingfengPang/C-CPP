#include <iostream>
//#include <stdint.h>
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a[5] = {150,100,400,300,350};
    int max = a[0];
    for(int i = 1;i<=5;i++){
        if(max<a[i])
            max = a[i];
    }
    cout << max << endl;


    //这里执行逆序
    int star = 0;
    int end = sizeof(a)/sizeof(a[0]) - 1;
    while(star < end){
        swap(&a[star],&a[end]);
        star++;
        end--;
    }
    for(int i = 0;i<5;i++)
        cout << a[i]<< " ";
    cout<<endl;
    //冒泡排序
    for(int i =0;i<4;i++){
        for(int j = 0;j<4-i;j++){
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }

    for(int i = 0;i<5;i++)
        cout << a[i]<< " ";
    system("pause");
    return 0;
}