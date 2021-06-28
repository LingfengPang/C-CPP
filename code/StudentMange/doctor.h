#ifndef DOCTOR_H
#define DOCTOR_H
#include "student.h"
#include <stdio.h>
class doctor:public student
{
private:
    /* data */
    int paper;
public:
    int getPaper(){return this->paper;}
    void setPaper(int papaer){this->paper = paper;}
    doctor(int id,string name,int age,string sex,int year,int scorce,int paper);
    ~doctor();
    void showInfo(){
        printf("Id:%4d,Name:%4s,Age:%3d,Sex:%6s,year:%4d,scorce:%3d,paper:%2d \n",
        this->getId(),"ss",this->getAge(),this->getSex(),this->getYear(),this->getScorce(),
        this->paper
        );
    }
};

doctor::doctor(int id,string name,int age,string sex,int year,int scorce,int paper):
student(id,name,age,sex,year,scorce)
{
    this->paper = paper;
}

doctor::~doctor()
{
}


#endif