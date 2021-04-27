#include <iostream>
//#include <stdint.h>
using namespace std;
bool is_sxh(int num)
{
    int n = num;
    int bit;
    int res = 0;
    for(int i = 0;i<3;i++){
        bit = num%10;
        num = num/10;
        res += (bit*bit*bit);
    }
    return (n == res);
}
int main()
{

    for(int i = 100;i<=999;i++){
        if(is_sxh(i))
            cout<<i<<endl;
    }
    system("pause");
}