#include <stdbool.h>
#include <stdio.h>

//有序表的一些查找方法
//二分法
int BinartSearch(int *a,int n,int key){
    int low,high,mid;
    low = 1;
    high = n;
    while(low<=high){
        mid = (low+high)/2;
        if(key<a[mid]){
            high = mid-1;
        }
        else if(key>a[mid]){
            low = mid+1;
        }
        else
            return mid;
    }
    return 0;
}

//斐波那契查找
int F[13];//斐波那契数列
int FibonacciSearch(int *a,int n,int key){
    int low, high,mid,i,k;
    low = 1;
    high = n;
    k = 0;
    while(n>F[k]-1){
        k++;
    }
    for(i = n;i<F[k]-1;i++){
        a[i] = a[n];
    }

    while(low <= high){
        mid = low+F[k-1]-1;
        if(key<a[mid]){
            high = mid - 1;
            k = k-1;
        }
        else if(key > a[mid]){
            low = mid+1;
            k = k-2;
        }
        else{
            
        }
    }
}