#include "student.h"
#include <iostream>
using namespace std;
void Student::show(){
    cout << this->name << ":"<<this->id<<endl;
}

int main(){
    Student st1;
    st1.setName("Wang");
    st1.setId(200);
    st1.show();
    system("pause");
    return 0;
}