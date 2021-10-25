#include <iostream>
//测试引用
int main(){
    int i = 1;
    const int &r =i;
    i = 2;
    std::cout << r;
    system("pause");
    return 0;
}