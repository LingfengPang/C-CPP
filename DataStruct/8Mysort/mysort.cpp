#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
//冒泡排序
void PrintVector(vector<int> v){
    for(int num:v)
        cout << num <<" ";
    cout << endl;
}
void BubbleSort(vector<int> &v){
    int i,j;
    bool flag = true;//防止排序好了还要继续搜索
    for(i = 0;i<v.size()&&flag;i++){
        flag = false;
        for(j = v.size()-2;j>=i;j--){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                flag = true;
            }
        }
    }
}

void SelectSort(vector<int> &v){
    int i,j,min;
    for(i = 0;i<v.size();i++){
        min = i;
        for(j = i+1;j<v.size();j++){
            if(v[min]>v[j])
                min = j;
        }
        if(i!=min)
            swap(v[i],v[min]);
    }
}


int main(){
    vector<int> v = {9,8,7,6,5,4,3,2,1};
    BubbleSort(v);
    PrintVector(v);
    system("pause");
    return 0;
}