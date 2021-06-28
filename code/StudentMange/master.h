#ifndef MASTER_H
#define MASTER_H
#include "student.h"
class master:public student
{
private:
    /* data */
    int partPro;
public:
    void setPartPro(int partPro){this->partPro = partPro;}
    int getPartPro(){return this->partPro;}
    master(int id,string name,int age,string sex,int year,int scorce,int partPro);
    ~master();
    void showInfo(){
        printf("Id:%4d,Name:%4s,Age:%3d,Sex:%6s,year:%4d,scorce:%3d,partPro:%2d \n",
        this->getId(),"ss",this->getAge(),this->getSex(),this->getYear(),this->getScorce(),
        this->partPro
        );
    }
};

master::master(int id,string name,int age,string sex,int year,int scorce,int partPro):
student(id,name,age,sex,year,scorce)
{
    this->partPro = partPro;
}

master::~master()
{
}

#endif