#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;
class Student
{
private:
    /* data */
    string name;
    int id;
public:
    void show();
    void setName(string name){this->name = name;}
    void setId(int ID){this->id = ID;}
};




#endif