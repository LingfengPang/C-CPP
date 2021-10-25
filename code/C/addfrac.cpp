//暂时觉得cout比scanf好用一点哈哈
#include <iostream>
#include <cmath>
using namespace std;
//判断素数

int gcd(int a,int b){
    if(a<b)
        return gcd(b,a);
    int r;
    while(a%b != 0){
        r = a%b;
        a = b;
        b = r;
    }
    return b;
}

int main(){
    int a1,a2;//分母
    int b1,b2;//分子
    cin >> a1>>b1;
    cin >> a2 >>b2;
    int c = a1*a2;
    int d = a1*b2+a2*b1;
    int mod = gcd(c,d);
    cout <<d/mod<<"/"<<c/mod<<endl;
    system("pause");
    return 0;
}