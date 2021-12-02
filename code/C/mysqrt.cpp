#include <iostream>
#include <cmath>
using namespace std;
//判断素数

double mysqrt(double num){
    double x = num;
    double y = 1;
    for(int i = 0;i<5;i++)
        y = (y+(x/y))/2;
    return y;


}

int main(){
    for(int i = 1;i<5;i++){
        cout << mysqrt(i)<<endl;
    }
    system("pause");
    return 0;
}