#include <iostream>
//#include <stdint.h>
using namespace std;
template <typename T>
void sort(T *arr,int size){
    for(int i = 0;i<size;i++){
        int min = i;
        for(int j = i+1;j<size;j++){
            if(arr[min]>arr[j])
                min = j;
        }
        if(min!=i){
            T temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    for(int i = 0;i<size;i++)
        cout << arr[i]<<" ";
}
int main()
{
    int a[5] = {5,4,3,2,1};
    char c[5] = {'f','e','d','b','a'};
    sort(a,5);
    cout <<endl;
    sort(c,5);
    cout <<endl;
    system("pause");
    return 0;
}