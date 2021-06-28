#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;
class student
{
private:
    /* data */
    int id;
    int age;
    string sex;
    int year;
    int scorce;
    string name;
public:
    virtual void showInfo() = 0;
    void setAge(int age){this->age = age;}
    int getAge(){return this->age;}
    void setId(int id){this->id = id;}
    int getId(){return id;}
    void setSex(string s){this->sex = s;}
    string getSex(){return this->sex;}
    void setYear(int year){this->year = year;}
    int getYear(){return this->year;}
    void setScorce(int scorce){this->scorce = scorce;}
    int getScorce(){return this->scorce;}
    void setName(string name){this->name = name;}
    string getName(){return this->name;}
    student(int id,string name,int age,string sex,int year,int scorce);
    ~student();
};
student::student(int id,string name,int age,string sex,int year,int scorce){
    this->id = id;
    this->age = age;
    this->sex = sex;
    this->year = year;
    this->scorce = scorce;
    this->name = name;
}


student::~student()
{
}

#endif