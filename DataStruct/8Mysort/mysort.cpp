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
void InsertSort(vector<int> &v){
    int i,j;
    int t = 0;//哨兵
    for(i = 1;i<v.size();i++){
        if(v[i]>v[i-1]){
            t = v[i];
            for(j = i-1;v[j]>t;j--)
                v[j+1]=v[j];
            v[j+1] = t;
        }
    }
}
//以gap进行插入排序
void shellSort(vector<int> &a)
{
    int len = a.size();
    int i, j, k, tmp, gap;  // gap 为步长
    for (gap = len / 2; gap > 0; gap /= 2) {  // 步长初始化为数组长度的一半，每次遍历后步长减半,
    	for (i = 0; i < gap; ++i) { // 变量 i 为每次分组的第一个元素下标 
	        for (j = i + gap; j < len; j += gap) { //对步长为gap的元素进行直插排序，当gap为1时，就是直插排序
	            tmp = a[j];  // 备份a[j]的值
	            k = j - gap;  // j初始化为i的前一个元素（与i相差gap长度）
	            while (k >= 0 && a[k] > tmp) {
	                a[k + gap] = a[k]; // 将在a[i]前且比tmp的值大的元素向后移动一位
	                k -= gap;
	            }
	            a[k + gap] = tmp; 
	        }
	    }
    }
}
void heapAdj(vector<int> &arr,int star,int end){
    int dad = star;
    int son = dad*2+1;//左孩子节点，son+1右孩子节点
    while(son<=end){
        if(son+1<=end &&arr[son]<arr[son+1])
            son++;
        if(arr[dad]>arr[son])
            return;
        else{
            swap(arr[dad],arr[son]);
            dad = son;
            son = dad*2+1;
        }
    }
}
void HeapSort(vector<int> &a){
    int i;
    int len = a.size();
    for(i = len/2-1;i>=0;i--){
        //对于每个堆进行调整，最大的放入根节点
        heapAdj(a,i,len-1);
    }
    for(i = len-1;i>0;i--){
        swap(a[0],a[i]);
        heapAdj(a,0,i-1);
    }
}
void merge(vector<int> &arr, int start, int mid, int end) {
	vector<int> result(100);
	int k = 0;
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]){
			result[k++] = arr[i++];
        }
		else{
			result[k++] = arr[j++];
        }
	}
	if (i == mid + 1) {
		while(j <= end)
			result[k++] = arr[j++];
	}
	if (j == end + 1) {
		while (i <= mid)
			result[k++] = arr[i++];
	}
	for (j = 0, i = start ; j < k; i++, j++) {
		arr[i] = result[j];
	}
}
 
void mergeSort(vector<int> &arr, int start, int end) {
	if (start >= end)
		return;
	int mid = start+( end - start ) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}

void MSort1(vector<int> &arr){
    mergeSort(arr,0,arr.size()-1);
}

int  Partition(vector<int> &arr,int low,int high){
    int mid;
    mid = arr[low];
    while(low<high){
        while(low<high&&arr[high]>=mid)
            high--;
        swap(arr[low],arr[high]);
        while(low<high&&arr[low]<=mid)
            low++;
        swap(arr[low],arr[high]);
    }
    return low;
}
void quickSort(vector<int> &arr,int low,int high){
    int mid;
    if(low<high){
        mid = Partition(arr,low,high);
        quickSort(arr,low,mid-1);
        quickSort(arr,mid+1,high);
    }
}
void QSort(vector<int> &arr){
    quickSort(arr,0,arr.size()-1);
}

int main(){
    vector<int> v = {9,8,7,6,5,4,3,2,1};
    QSort(v);
    PrintVector(v);
    system("pause");
    return 0;
}