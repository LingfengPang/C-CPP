#include <iostream>
//#include <stdint.h>

using namespace std;
bool isSeven(int num)
{
    if(num%7 == 0)
        return true;
    else if(num%10 == 7)
        return true;
    else if(num>=70&&num<=79)
        return true;
    return false;
}
int main()
{

    for(int i = 1;i<=99;i++){
        if(isSeven(i))
            cout<<i<<endl;
    }
    system("pause");
}