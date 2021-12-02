#include <iostream>
#include <cmath>
using namespace std;
// int splite(int a[],int low,int high){
//     int part_elemt = a[low];
//     while(1){
//         while(low<high &&a[high]>= part_elemt){
//             high--;
//         }
//         if(low >=high) break;
//         a[low++] = a[high];
//         while(low<high &&a[low]<= part_elemt){
//             low++;
//         }
//         if(low >=high) break;
//         a[high--] = a[low];
//     }
//     a[high] = part_elemt;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
//     return high;
// }
// void quicksort(int a[],int low,int high){
//     int middle;
//     if(low>=high) return;
//         middle = splite(a,low,high);
//     quicksort(a,low,middle-1);
//     quicksort(a,middle+1,high);
// }

int splite(int a[],int low,int high){
    int temp = a[low];
    while(1){
        while(low<high&&a[low]<a[high])
            high--;
        if(low>=high) break;
        a[low++] = a[high];
        while(low<high&&a[low]<a[high])
            low++;
        if(low>=high) break;
        a[high--] = a[low];
    }
    a[high] = temp;
    return high;

}
void quicksort(int a[],int low,int high){
    int middle;
    if(low>=high) return;
    middle = splite(a,low,high);
    quicksort(a,low,middle-1);
    quicksort(a,middle+1,high);
}

int main(){
    int a[5] = {4,5,2,1,3};
    quicksort(a,0,4);
    for(auto n:a)
        cout << n<<endl;
    system("pause");
    return 0;
}