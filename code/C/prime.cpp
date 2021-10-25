#include <iostream>
#include <cmath>
using namespace std;
//判断素数
bool isprime(int n){
    if(n<=1)
        return false;
    int d = sqrt(n);
    for(int i = 2;i<=d;i++){
        if(n%i == 0)
            return false;
    }
    return true;
}


int main(){
    cout<<isprime(70)<<endl;
    system("pause");
}