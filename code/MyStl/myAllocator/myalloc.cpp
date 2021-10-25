#include "myalloc.h"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int ia[5] = {0,1,2,3,4};
    //unsigned int i;
    vector<int,TREE::allocator<int>>iv(ia,ia+5);
    for(int n:iv){
        cout <<n<<endl;
    }
    system("pause");
    return 0;
}