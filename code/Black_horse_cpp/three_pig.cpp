#include <iostream>
//#include <stdint.h>
using namespace std;

int main()
{
    int a,b,c;
    char ch = 'A';
    int max = a;
    cout << "Please Input 3 pigs' age"<<endl;
    cin >> a >> b >> c;
    cout << "A is "<<a<<endl;
    cout << "B is "<<b<<endl;
    cout << "C is "<<c<<endl;
    if(max < b){
        max = b;
        ch = 'B';
    }

    if(max < c){
        max = c;
        ch = 'C';
    }

    cout << ch<<" is old! it is "<<max<<endl;
    system("pause");
}