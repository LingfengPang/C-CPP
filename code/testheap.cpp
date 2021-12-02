#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;


class Myheap{
    private:
        vector<int> heap;
        const int SIZE = 10;
            //上浮
        void swim(int pos){
            while(pos>0&&heap[(pos-1)/2]<heap[pos]){
                swap(heap[(pos-1)/2],heap[pos]);
                pos=(pos-1)/2;
            }
        }

    //下沉
        void sink(int pos){
            while(2*pos+1 <=SIZE){
                int i = 2*pos+1;//左子树
                if(i<heap.size()&&heap[i]<heap[i+1])
                    ++i;
                if(heap[pos]>=heap[i]) break;
                swap(heap[pos],heap[i]);
                pos = i;
            }
        }
    public:
        Myheap(){
            //heap.push_back(0);//0位置放的是最大值
            for(int i = 0;i<10;i++){
                push(i+1);
            }
            //heap[0] = heap[1];
        }

        void showArray(){
            for(int i = 0;i<heap.size();i++){
                cout << heap[i]<<" ";
                //Myheap();
            }
            cout <<endl;
        }
        void showSort(){
            for(int i = 0;i<SIZE;i++){
                cout << top() << " "<<endl;
                pop();
                //showArray();
            }
            cout <<endl;
        }
    //获得最大值
        int top(){
            return heap[0];
        }

        //插入任意值
        void push(int k){
            heap.push_back(k);
            swim(heap.size()-1);
        }

        //删除最大值
        void pop(){
            //把最后一个数挪到开头
            heap[0] = heap.back();
            heap.pop_back();
            sink(0);
        }


};



int main(){
    Myheap *h = new Myheap();
    h->showArray();
    h->showSort();
    system("pause");
    return 0;

}