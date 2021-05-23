#include <iostream>
#include <string>
//#include <stdint.h>
using namespace std;
struct Student
{
    /* data */
    string name;
    int scorce;
    
};

struct Teacher
{
    /* data */
    string name;
    Student student[5];
};

int main(){
    Teacher teacher[3];
    for(int i = 0;i<3;i++){
        cin >> teacher[i].name;
        for(int j = 0;j<5;j++){
            cin >> teacher[i].student[j].name;
            cin >> teacher[i].student[j].scorce;
        }
    }

        for(int i = 0;i<3;i++){
        cout << teacher[i].name <<" : ";
        for(int j = 0;j<5;j++){
            cout << teacher[i].student[j].name<<" ";
            cout << teacher[i].student[j].scorce<<" ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}