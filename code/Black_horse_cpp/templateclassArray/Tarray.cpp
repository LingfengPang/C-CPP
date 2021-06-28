#include <iostream>
#include <windows.h>
#include "Tarray.hpp"

int main(){
    myArray<int> a1(5);
    for(int i = 0;i<5;i++){
        a1.push_back(i+1);
    }
    for(int i = 0;i<5;i++){
       std::cout << a1[i] << std::endl;
    }
    system("pause");
    return 0;
}