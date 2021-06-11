#include "computer.h"
#include <string>
#include <iostream>
using namespace std;
void Intel::calculate(){
    cout <<"Intel yes"<<endl;
}

void Amd::calculate(){
    cout <<"Amd yes"<<endl;
}

Computer::~Computer(){
    if(cpu != nullptr){
        delete cpu;
        cpu = nullptr;  
    }
}
int main(){
    CPU *cpu1 = new Intel;
    CPU *cpu2 = new Amd;
    Computer *c1 = new Computer(cpu1);
    Computer *c2 = new Computer(cpu2);
    c1->work();
    c2->work();
    system("pause");
    return 0;
}